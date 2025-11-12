#include<bits/stdc++.h>
#define Xor ^ 
using namespace std;
int n,k,ans;
int a[(int)1e5+1];
bool check(int l,int r){
	int ans=a[l];
	for(int i=l+1;i<=r;i++){
		ans=ans^a[i]; 
	}
	return ans==k? true : false;
}
int main(){
//	freopen("xor4.in","r",stdin);
//	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int l=1,r=n;
	while(r!=(l+r)/2){
	//	printf("LOOP: %d\n",i);
		int ansx=-0x3f,ansy=0x3f3f;
		bool flag=false;
		while(true){
			int mid=(l+r)/2;
//			printf("l:%d r:%d mid:%d a[l]: %d a[r]: %d check(l,r): %d TYPE:LS\n",l,r,mid,a[l],a[r],check(l,r));
			if(r==mid&& !check(l,r)){
				flag=true;
				ans++;
				break;
			}
			if(check(l,r)){
				if(abs(ansx-ansy)==abs(l-r)){
					break;
				}
//				printf("[FIND ANSWER]l: %d r: %d abs(l-r): %d abs(ansx-ansy): %d\n",l,r,abs(l-r),abs(ansx-ansy));
				if(abs(ansx-ansy)>abs(l-r)){
					ansx=l;ansy=r;
	//				cout<<"CONTINUE!!!\n";
				}
			}
			r=mid;
		}
		l=r+1;r=n;
//		if(flag){
//			l=r+1;r=n;
//			continue;
//		}
//		ansx=-0x3f;ansy=0x3f3f;
//		while(l<=r){
//			int mid=(l+r)/2;
//			printf("l:%d r:%d mid:%d a[l]: %d a[r]: %d check(l,r): %d TYPE: RS\n",l,r,mid,a[l],a[r],check(l,r));
//			if(check(l,r)){
//				if(abs(ansx-ansy)==abs(l-r)){
//					ans++;
//					cout<<"FK CSPJ!!!";
//					break;
//				}
//				printf("%d %d %d\n",l,r,check(l,r));
//				if(abs(ansx-ansy)>abs(l-r)){
//					ansx=l;ansy=r;
//					cout<<"CONTINUE!!!\n";
//				}
//			}
//			l=mid+1;
//		}
	}
	printf("%d",ans);
}
