#include<bits/stdc++.h>
using namespace std;
int cnt1=0,cnt2=0,cnt3=0;
int t,n;
int a[6][100005];
struct kh{
	int id;
	int ch;
	int bm;
};
bool cmp(kh a,kh b){
	return a.ch>b.ch;
}
void chack1(){
	kh x[100005];
	if(cnt1>n/2){
		for(int i=1;i<=n;i++){
			if(a[5][i]!=1) continue;
			if(a[1][i]-a[2][i]<a[1][i]-a[3][i]){
				x[i].id=i;
				x[i].ch=a[1][i]-a[2][i];
				x[i].bm=2; 
			}
			else{
				x[i].id=i;
				x[i].ch=a[1][i]-a[3][i];
				x[i].bm=3;
			}
		}
		sort(x+1,x+1+n,cmp);
		int len=cnt1-n/2;
		for(int i=1;i<=len;i++){
			a[4][x[i].id]=a[x[i].bm][x[i].id];
			a[5][x[i].id]=x[i].bm;
			cnt1--;
			if(x[i].bm==2){
				cnt2++;
				//chack2();
			}else{
				cnt3++;
				//chack3();
			}
		}
	}
}
void chack2(){
	kh x[100005];
	if(cnt2>n/2){
		for(int i=1;i<=n;i++){
			if(a[5][i]!=2) continue; 
			if(a[2][i]-a[1][i]<a[2][i]-a[3][i]){
				x[i].id=i;
				x[i].ch=a[2][i]-a[1][i];
				x[i].bm=1;
			}
			else{
				x[i].id=i;
				x[i].ch=a[2][i]-a[3][i];
				x[i].bm=3;
			}
		}
		sort(x+1,x+1+n,cmp);
		int len=cnt2-n/2;
		for(int i=1;i<=len;i++){
			a[4][x[i].id]=a[x[i].bm][x[i].id];
			a[5][x[i].id]=x[i].bm;
			cnt2--;
			if(x[i].bm==1){
				cnt1++;
				//chack1();
			}else{
				cnt3++;
				//chack3();
			}
		}
	}
}
void chack3(){
	kh x[100005];
	if(cnt3>n/2){
		for(int i=1;i<=n;i++){
			if(a[5][i]!=3) continue;
			if(a[3][i]-a[1][i]<a[3][i]-a[2][i]){
				x[i].id=i;
				x[i].ch=a[3][i]-a[1][i];
				x[i].bm=1;
			}
			else{
				x[i].id=i;
				x[i].ch=a[3][i]-a[2][i];
				x[i].bm=2;
			}
		}
		sort(x+1,x+1+n,cmp);
		int len=cnt3-n/2;
		for(int i=1;i<=len;i++){
			a[4][x[i].id]=a[x[i].bm][x[i].id];
			a[5][x[i].id]=x[i].bm;
			cnt3--;
			if(x[i].bm==1){
				cnt1++; 
				//chack1();
			}else{
				cnt2++;
				//chack2();
			}
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		cnt1=0,cnt2=0,cnt3=0;	
		for(int i=1;i<=n;i++){
			cin>>a[1][i]>>a[2][i]>>a[3][i];
			a[4][i]=0;
			a[4][i]=max(a[1][i],max(a[2][i],a[3][i]));
			if(a[4][i]==a[1][i]) {
				cnt1++;
				a[5][i]=1;
			}
			else if(a[4][i]==a[2][i]) {
				cnt2++;
				a[5][i]=2;
			}
			else if(a[4][i]==a[3][i]) {
				cnt3++;
				a[5][i]=3;
			}
		}
		//while(1){
			chack1();
			chack2();
			chack3();
			//if(cnt1<=n/2&&cnt2<=n/2&&cnt3<=n/2) break;
			 
		//}
		
		int ans=0;
		for(int i=1;i<=n;i++){
			ans+=a[4][i];
		}
		cout<<ans<<endl;
	}
	return 0;
}