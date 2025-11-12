#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
long long n,m,cnt=0;
string a[5000],b[5000],c,d;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	while(m--){
		cin>>c>>d;
		int l=0,r=int(c.size())-1;
		string sr1="",sr2="";
		while(l<=r){
			if(c[l]==d[l]){
				l++;
			}else if(c[r]==d[r]){
				r--;
			}else{
				break;
			}
		}
		for(int i=l;i<=r;i++){
			sr1=sr1+c[i];
		}
		for(int i=l;i<=r;i++){
			sr2=sr2+d[i];
		}
		int len1=(int)(sr1.size());
		int len2=(int)(sr2.size());
		for(int i=1;i<=n;i++){
			bool f1=0,f2=0;
			int op=0;
			for(int j=0;j<int(a[i].size());j++){
				if(sr1[op]==a[i][j]){
					op++;
				}else{
					if(op!=0){
					
						if(op==len1){
							f1=1;
							break;
						}else{
							op=0;
						}
					}
				}
				
			}
			if(op!=0){	
				if(op==len1){
					f1=1;
					
				}else{
					op=0;
				}
			}
			op=0;
			for(int j=0;j<int(b[i].size());j++){
				if(sr2[op]==b[i][j]){
					
					op++;
				}else{
					if(op!=0){
						if(op==len2){
							f2=1;
							break;
						}else{
							op=0;
						}
					}
				}
				
			}
			if(op!=0){
				if(op==len2){
					f2=1;
					
				}else{
					op=0;
				}
			}
			if(f1==1&&f2==1){
				cnt++;
			}
			
		}
		cout<<cnt<<endl;
		cnt=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

