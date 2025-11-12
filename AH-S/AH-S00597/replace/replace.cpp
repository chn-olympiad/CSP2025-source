#include<bits/stdc++.h>
using namespace std;
int n,q;
string a[200005];
string b[200005];
string a1[200005];
string b1[200005];
//string f[200005];
int sum;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int st=1;st<=q;st++){
		cin>>a1[st]>>b1[st];		
		sum=0;
		for(int i=1;i<=n;i++){
			int k=0,km=a[i].size(),d=-1;
			int x=a1[st].size();
			for(int j=0;j<=x-1;j++){
				//f[st][j]=a1[st][j];
				if(a[i][k]==a1[st][j]){
					if(k==km-1)break;
					k++;continue;
				}
				k=0;d=j;
			}
			k++;
			if(k==km){
				bool a=true;
				//cout<<"111"<<k<<' '<<d<<endl;
				for(int j=0;j<=x-1;j++){
					//cout<<j;
					if(j>d&&j<=d+k){
					  //cout<<" "<<b[i][j-d-1]<<" "<<b1[st][j]<<endl;
					  if(b[i][j-d-1]!=b1[st][j]){a=false;break;}
					}
					else {
						//cout<<"   "<<a1[st][j]<<" "<<b1[st][j];
						if(a1[st][j]!=b1[st][j]){a=false;break;}
					}
				}
				if(a)sum++;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}	
