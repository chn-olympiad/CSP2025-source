#include<bits/stdc++.h>//提高组太难了根本不会T O T 
#define ll long long
using namespace std;
inline ll read(){
	short f=1;
	ll o=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}//==P==b
	while(c>='0'&&c<='9'){
		o=o*10+(c-'0');
		c=getchar();
	}
	return o*f;
}
ll n,T,a[100005][4],b[100005],c[5],ans,zz,cz[100005],man[20005],maxx;
ll M(ll i,ll k){

if(k==1)return max(a[i][1],max(a[i][2],a[i][3]));
if(k==3)return min(a[i][1],min(a[i][2],a[i][3]));
else return a[i][1]+a[i][2]+a[i][3]-M(i,1)-M(i,3);
}
//buhuiyiweiwowanyouxiba?
//womeiyoua
ll mm(ll i,ll k){
	if(k==1){
		if(a[i][1]>a[i][2]&&a[i][1]>a[i][3])return 1;
		else if(a[i][2]>a[i][1]&&a[i][2]>a[i][3])return 2;
		return 3;
	}
	if(k==3){
		if(a[i][1]<a[i][2]&&a[i][1]<a[i][3])return 1;
		else if(a[i][2]<a[i][1]&&a[i][2]<a[i][3])return 2;
		return 3;
	}
	else{
		return 6-mm(i,1)-mm(i,3);
	}
}
ll m;
void PE(){
	ans=0;
	ll a1=0,a2=0,a3=0;
	for(int i=1;i<=n;i++){
	/*	if(man[i]==1)a1++;
		else if(man[i]==2)a2++;
		else a3++;*/
		ans+=a[i][man[i]];
	}
	//if(a1<=n/2&&a2<=n/2&&a3<=n/2)
	maxx=max(ans,maxx);
}
void SU(ll x,ll a1,ll a2,ll a3){
	if(x==n+1){
		PE();return;
	}
	//I am so fuck!
	man[x]=1;a1++;
	if(a1>m){
		a1--;
	}else
	{
	SU(x+1,a1,a2,a3);a1--;}
	man[x]=2;a2++;
	if(a2>m)a2--;else
	SU(x+1,a1,a2,a3),a2--;
	man[x]=3;a3++;if(a3>m)return;
	SU(x+1,a1,a2,a3);
	return;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    
    /*思路：先全部调去最喜欢的社团，
	在从社团中调整2次（best=>ok=>bad），损失低的优先 */
/*	T=read();
	while(T--){
		memset(man,0,sizeof(man));
		memset(b,0,sizeof(b)),memset(cz,0,sizeof(cz)),c[1]=0,c[2]=0,c[3]=0,zz=0;
		ans=0;
		n=read();
		for(int i=1;i<=n;i++){
			a[i][1]=read(),a[i][2]=read(),a[i][3]=read();
			if(a[i][1]>a[i][2]&&a[i][1]>a[i][3])b[i]=1,c[1]++;
			else if(a[i][2]>a[i][1]&&a[i][2]>a[i][3])b[i]=2,c[2]++;
			else b[i]=3,c[3]++;
			{
				man[M(i,1)-M(i,2)]=1;
				zz++;
				cz[zz]=M(i,1)-M(i,2); 
			}
			ans+=M(i,1);
		}
		if(c[1]<=n/2&&c[2]<=n/2&&c[3]<n/2){
			printf("1 %lld\n",ans);continue;
		}
		sort(cz+1,cz+zz);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=zz;j++){
				if(M(i,1)-M(i,2)==cz[j]){
					swap(a[i][1],a[j][1]);
					swap(a[i][2],a[j][2]);
					swap(a[i][3],a[j][3]);
					break;
				}
			}
		}
		for(int i=1;i<=n;i++){
			cout<<a[i][1]<<" "<<a[i][2]<<" "<<a[i][3]<<endl;
		}
		cout<<"ans"<<ans<<'\n';
		bool f=0;
		for(int i=1;i<=n;i++){
			cout<<"M"<<M(i,1)<<" "<<M(i,2)<<endl;
			ans-=(M(i,1)-M(i,2));
			c[mm(i,1)]--;
			c[mm(i,2)]++;
			if(c[1]<=n/2&&c[2]<=n/2&&c[3]<n/2){
			printf("2 %lld\n",ans);f=1;break;
		}
		}b 
		}
		if(f)continue;
		memset(man,0,sizeof(man));
		zz=0;
		memset(cz,0,sizeof(cz));
		for(int i=1;i<=n;i++){
				{
				man[M(i,2)-M(i,3)]=1;
				zz++;
				cz[zz]=M(i,2)-M(i,3); 
			}
		}
		sort(cz+1,cz+zz);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=zz;j++){
				if(M(i,2)-M(i,3)==cz[j]){
					swap(a[i][1],a[j][1]);
					swap(a[i][2],a[j][2]);
					swap(a[i][3],a[j][3]);
					break;
				}
			}
		}
		f=0;
		for(int i=1;i<=n;i++){
			ans-=(M(i,2)-M(i,3));
			c[mm(i,2)]--;
			c[mm(i,3)]++;
			if(c[1]<=n/2&&c[2]<=n/2&&c[3]<n/2){
			printf("3 %lld\n",ans);f=1;break;
		}
		}
		if(f)continue;
		else{
			printf("0\n");
		}
	}
	//600606066006000000000000
//	system("cls");*/
bool TXA=1;
    T=read();
	while(T--){
		TXA=0;
		maxx=0;//
		n=read();
		m=n/2;
		for(int i=1;i<=n;i++){
			a[i][1]=read(),a[i][2]=read(),a[i][3]=read();
			if(a[i][2]!=0||a[i][3]!=0)TXA=0; 
		}
		if(TXA){
			ans=0;
			ll yeah[100005];
			for(int i=1;i<=n;i++){
				yeah[i]=a[i][1];
			}
			sort(yeah+1,yeah+1+n);
			for(int i=n;i>n/2;i++)ans+=yeah[i];
			printf("%lld\n",ans);
		} 
		SU(1,0,0,0);
		printf("%lld\n",maxx);
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*5 
10 
2020 14533 18961 
2423 15344 16322 
1910 6224 16178 
2038 9963 19722 
8375 10557 5444 
3518 14615 17976 
6188 13424 16615 
8769 509 4394 
958 3195 9953 
16441 5313 10926 
10 
5491 4476 6362 
9805 9130 15480 
9090 9901 10480 
6326 6516 1985 
9119 2924 6420 
9826 12689 7592 
7293 16544 12901 
11905 18183 18712 
9015 3463 13025 
1792 2433 17042 
10 
3004 4255 17336 
11894 5756 17092 
8150 14715 10991 
5149 16652 16780 
11524 11996 5433 
7690 10472 19935 
1184 6516 9246 
3231 5570 10010 
8426 16992 4654 
18955 13977 16657 
10 
6839 5455 15586 
11767 12919 2643 
13775 8904 19938 
13717 11997 15170 
13707 2404 17497 
3471 2462 8073 
18467 14346 18663 
13582 4839 15785 
11875 7476 12308 
8568 3134 18522 
10 
14230 3941 18854 
12173 19429 15426 
10974 4717 15290 
4732 6608 4961 
13198 13925 2137 
10688 3092 16965 
5356 19920 1471 
11299 10796 13511 
17932 12143 16407 
5611 8100 16107 
*/

