#include<bits/stdc++.h>
using namespace std;
int T,n;
struct man{
	int la,lb,lc;
};
bool cmp1(man x,man y){
	if(x.la==y.la){
		if(x.lb==y.lb) return x.lc<y.lc;
		return x.lb<y.lb;
	}
	return x.la<y.la;
}
bool cmp2(man x,man y){
	if(x.la==y.la){
		if(x.lb==y.lb) return x.lc>y.lc;
		return x.lb>y.lb;
	}
	return x.la>y.la;
}
int run(man a[]){
	int sa1=0,sb1=0,sc1=0,na1=0,nb1=0,nc1=0,nx=n/2;
	for(int i=0;i<n;i++){
		int ma=a[i].la,mb=a[i].lb,mc=a[i].lc;
		if(ma>=mb&&ma>=mc&&na1<nx){
			na1++;
			sa1+=ma;
			continue;
		}
		if((mb>=ma&&mb>=mc&&nb1<nx)||na1>=nx){
			nb1++;
			sb1+=mb;
			continue;
		}
		if((mc>=mb&&mc>=ma&&nc1<nx)||na1>=nx||nb1>=nx){
			nc1++;
			sc1+=mc;
			continue;
		}
	}
	return sa1+sb1+sc1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		man a[100010],o,p;
		for(int i=0;i<n;i++) cin>>a[i].la>>a[i].lb>>a[i].lc;
		sort(a,a+n,cmp1);
		int maxi=run(a);
		sort(a,a+n,cmp2);
		maxi=max(maxi,run(a));
		cout<<maxi<<endl;
	}
	fclose(stdout);
	fclose(stdin);
}
