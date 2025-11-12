#include<bits/stdc++.h>
using namespace std;
bool cmp(int r,int l){
	return r>l;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		int n,a[10005],b[10005],c[10005],x=0,y=0,z=0;
		int cnt=0;
		cin >> n;
		for(int i=0;i<n;i++){ 
			cin >> a[i] >> b[i] >> c[i];
			if(a[i]>=b[i]&&a[i]>=c[i]){
				cnt+=a[i];
				x++;
			}else if(b[i]>=a[i]&&b[i]>=c[i]){
				cnt+=b[i];
				y++;
			}else{
				cnt+=c[i];
				z++;
			}
		}
		if(n==2){
			if(max(a[0],b[0],c[0])<=a[1]){
				cout << a[1]+max(b[0],c[0]) << endl;
				continue;
			}else if(max(a[0],b[0],c[0])<=b[1]){
				cout << b[1]+max(a[0],c[0]) << endl;
				continue;
			}else if(max(a[0],b[0],c[0])<=c[1]){
				cout << c[1]+max(a[0],b[0]) << endl;
				continue;
			}else if(max(a[1],b[1],c[1])<=a[0]){
				cout << a[0]+max(b[1],c[1]) << endl;
				continue;
			}else if(max(a[1],b[1],c[1])<=b[0]){
				cout << b[0]+max(a[1],c[1]) << endl;
				continue;
			}else if(max(a[1],b[1],c[1])<=c[0]){
				cout << c[0]+max(a[1],b[1]) << endl;
				continue;
			}
		}
		if(x<=n/2&&y<=n/2&&z<=n/2){
			cout <<cnt <<endl;
		}else{
			cnt=0;
			if(x>n/2){
				sort(a,a+n,cmp);
				for(int i=0;i<n/2;i++){
					cnt+=a[i];
				}
			}
			if(y>n/2){
				sort(b,b+n,cmp);
				for(int i=0;i<n/2;i++){
					cnt+=b[i];
				}
			}
			if(z>n/2){
				sort(c,c+n,cmp);
				for(int i=0;i<n/2;i++){
					cnt+=c[i];
				}
			}
			cout << cnt << endl;
		}
	}
	return 0;
} 
