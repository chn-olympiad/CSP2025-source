#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5; 
long long n,k,a[N];
bool flag1=true,flag2=true,flag3=true;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		flag1=((a[i]==1)&&(flag1));
		flag2=((a[i]==0)&&(flag2));
		flag3=((a[i]<2)&&(flag3));
	}
	if(flag3){
		if(flag1){
			if(k==1){
				cout << n;
			}else if(k==0){
				cout << n/2;
			}else{
				cout << 0;
			}
		}else{
			if(k>1){
				cout << 0;
			}else if(k==0){
				if(flag2){
					cout << n;
				}else{
					long long cnt=0;
					for(int i=1;i<=n;i++){
						if(a[i]==0){
							cnt++;
						}else if(a[i]==1){
							if(a[i+1]==1&&i+1<=n){
								cnt++;
								i++;
							}
						}
					}
					cout << cnt;
				}
			}else if(k==1){
				long long cnt=0;
				for(int i=1;i<=n;i++){
					if(a[i]==1){
						cnt++;
					}else if(a[i]==0){
						if(a[i+1]==0&&i+1<=n){
							cnt++;
							i++;
						}
					}
				}
				cout << cnt;
			}
		}
	}else{
		cout << n;
	}
}
