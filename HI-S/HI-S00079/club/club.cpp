#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
struct node{
	int a1,a2,a3;
}a[2];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		int n,cnt=0,b[100005]={},c,d;
		cin >> n;
		if(n==2){
				cin >> a[0].a1 >> a[0].a2 >> a[0].a3;
				cin >> a[1].a1 >> a[1].a2 >> a[1].a3;
				if(max(max(max(max(max(a[0].a1,a[0].a2),a[0].a3),a[1].a1),a[1].a2),a[1].a3)==a[0].a1){
					cnt+=a[0].a1+max(a[1].a2,a[1].a3);
				}
				else if(max(max(max(max(max(a[0].a1,a[0].a2),a[0].a3),a[1].a1),a[1].a2),a[1].a3)==a[0].a2){
					cnt+=a[0].a2+max(a[1].a1,a[1].a3);
				}
				else if(max(max(max(max(max(a[0].a1,a[0].a2),a[0].a3),a[1].a1),a[1].a2),a[1].a3)==a[0].a3){
					cnt+=a[0].a3+max(a[1].a1,a[1].a2);
				}
				else if(max(max(max(max(max(a[0].a1,a[0].a2),a[0].a3),a[1].a1),a[1].a2),a[1].a3)==a[1].a1){
					cnt+=a[1].a1+max(a[0].a2,a[0].a3);
				}
				else if(max(max(max(max(max(a[0].a1,a[0].a2),a[0].a3),a[1].a1),a[1].a2),a[1].a3)==a[1].a2){
					cnt+=a[1].a2+max(a[0].a1,a[0].a3);
				}
				else if(max(max(max(max(max(a[0].a1,a[0].a2),a[0].a3),a[1].a1),a[1].a2),a[1].a3)==a[1].a3){
					cnt+=a[1].a3+max(a[0].a2,a[0].a1);
				}
				cout << cnt << endl;
		}
		else{
			for(int i=1;i<=n;i++){
				cin >> b[i] >> c >> d;
			}
			sort(b+1,b+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				cnt+=b[i];
			}
			cout << cnt << endl;
		}
	}
	return 0;
} 
