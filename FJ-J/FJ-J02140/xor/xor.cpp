#include<bits/stdc++.h>
using namespace std;
int a[5000],b[5000],c,d,e,n;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>c;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		d=a[i];
		if(b[i]==1){
			
		}else{
			for(int j=i+1;j<=n;j++){
				if(d==c){
					for(int z=i;z<j;z++){
						b[z]=1;
					}
					e++;
//					cout<<i<<" "<<j<<" "<<d<<endl;
					break;
				}else{
					if(b[j]==1){
						break;
					}else{
						d=d^a[j];
					}
				}
			}
		}
	}
	cout<<e;
/*	cout<<endl;
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	for(int i=1;i<=n;i++){
		cout<<b[i]<<" ";
	}*/

	return 0;
}

