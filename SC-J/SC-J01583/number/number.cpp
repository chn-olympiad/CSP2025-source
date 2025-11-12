#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int a[2005];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size();
	int mx=-1e9,mn=1e9;
	sort(a+1,a+1+l);
	for(int i=1;i<=l;i++){
		if(l==1){
			cout<<s;
			break;
		}else{
			if(l==2){
				mx=max(a[1],a[2]);
				cout<<mx<<endl;
				mn=min(a[1],a[2]);
				cout<<mx<<mn;
				break;
			}else{
				if(l==3){
					mx=max(a[1],max(a[2],a[3]));
					mn=min(a[1],min(a[2],a[3]));
					if(mx==a[1]&&mn==a[3]){
						cout<<a[1]<<a[2]<<a[3];
						break;
					}else{
						if(mx==a[1]&&mn==a[2]){
							cout<<a[1]<<a[3]<<a[2];
							break;
						}else{
							if(mx==a[2]&&mn==a[1]){
								cout<<a[2]<<a[3]<<a[1];
								break;
							}else{
								if(mx==a[2]&&mn==a[3]){
									cout<<a[2]<<a[1]<<a[3];
									break;
								}else{
									if(mx==a[3]&&mn==a[1]){
										cout<<a[3]<<a[2]<<a[1];
										break;
									}else{
										if(mx==a[3]&&mn==a[2]){
											cout<<a[3]<<a[1]<<a[2];
											break;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return 0;
}