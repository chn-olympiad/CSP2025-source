#include<bits/stdc++.h>
using namespace std;
// pts-80~100
const int Maxn=500000;
int a[Maxn];
int n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(k<=255){
		char v[n][256];
		memset(v,'0',sizeof(v));
		int count=0;
		if(a[0]!=k){
			v[0][a[0]]='1';
		}
		else count++;
		for(int i=1;i<n;i++){
			int y=a[i]^k;
			if(v[i-1][y]=='1' or a[i]==k){
				count++; 
			}
			else{
				v[i][a[i]]='1';
				for(int j=0;j<256;j++){
					if(v[i-1][j]=='1'){
						v[i][j^a[i]]='1';
					}
				}
			}	
		}
		cout<<count;
	} 
	else{
		int count=0;
		vector<int> t[n];
		if(a[0]!=k) t[0].push_back(a[0]);
		else{
			count++;
		}
		for(int i=1;i<n;i++){
			bool jr=true;
			int y=a[i]^k;
			int r=0,l=(t[i].size()-1);
			if(a[i]==k){
				count++;
				continue;
			}
			if(jr){
				vector<int> q;
				bool r[k+1]={};
				int vs[n+1];
				memset(r,false,sizeof(r));
				vs[0]=a[i];
				r[a[i]]=true;
				for(int j=0;j<t[i-1].size();j++){
					
					int o=a[i]^t[i-1][j];
					if(o==k){
						count++;
						jr=false;
						break;
					}
					if(!r[o]) vs[j+1]=o;
					r[o]=true;
				}
				if(jr){
					sort(vs,vs+t[i-1].size()+1);
					for(int j=0;j<t[i-1].size()+1;j++){
						t[i].push_back(vs[j]);
					}
				}
				
			}
			
		} 
		cout<<count;
	}
	return 0;
} 
