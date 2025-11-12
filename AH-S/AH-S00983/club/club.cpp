#include<bits/stdc++.h>
using namespace std;
int T,n,cnt[10];
int a[100005][10];
long long ans;
struct ca{
	long long chaa;
	int id;
}cha[100005];
bool cmp(ca x,ca y){
	return x.chaa<y.chaa;
}
void read(int &x){
	int f=1;
	x=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	x*=f;
}
int mx(int x){
	if(a[x][1]>=a[x][2]&&a[x][1]>=a[x][3]){
		return 1;
	}
	if(a[x][2]>=a[x][1]&&a[x][2]>=a[x][3]){
		return 2;
	}
	return 3;
}
int md(int x){
	if((a[x][1]>=a[x][2]&&a[x][2]>=a[x][3])||(a[x][3]>=a[x][2]&&a[x][2]>=a[x][1])){
		return a[x][2];
	}
	if((a[x][2]>=a[x][1]&&a[x][1]>=a[x][3])||(a[x][3]>=a[x][1]&&a[x][1]>=a[x][2])){
		return a[x][1];
	}
	return a[x][3];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	read(T);
	while(T--){
		read(n);
		ans=0;
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;i++){
			read(a[i][1]);read(a[i][2]);read(a[i][3]);
			ans+=(long long)(a[i][mx(i)]);
			cnt[mx(i)]++;
			cha[i].chaa=a[i][mx(i)]-md(i);
			cha[i].id=mx(i);
		}
		int chu=max(max(cnt[1],cnt[2]),cnt[3])-(n/2);
		int idd;
		if(cnt[1]>=n/2){
			idd=1;
		}else if(cnt[2]>=n/2){
			idd=2;
		}else{
			idd=3;
		}
		sort(cha+1,cha+n+1,cmp);
		for(int i=1;i<=n&&chu>0;i++){
			if(idd==cha[i].id){
				ans-=cha[i].chaa;
				chu--;
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
