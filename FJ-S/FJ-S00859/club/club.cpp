#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int q,n,a[100001],b[100001],c[100001],num=0;
	cin>>q;
	while(q--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		for(int i=1;i<=n;i++){
			if(a[i]>=b[i] && a[i]>=c[i]){
				num+=a[i];
			}else if(b[i]>=a[i] && b[i]>=c[i]){
				num+=b[i];
			}else{
				num+=c[i];
			}
		}
		cout<<num<<endl;
		num=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
