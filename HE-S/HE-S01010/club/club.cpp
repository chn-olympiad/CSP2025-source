#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
struct stu{
	int a,b,c;
};
bool cmp1(stu x,stu y){
	return x.a>y.a;
}
bool cmp2(stu x,stu y){
	return x.b>y.b;
}
bool cmp3(stu x,stu y){
	return x.c>y.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdin);
	int t;cin>>t;
	for(int z=0;z<t;z++){
		int n;cin>>n;
		stu sa[n];
		stu sb[n];
		stu sc[n];
		for(int i=0;i<n;i++){
			cin>>sa[i].a>>sa[i].b>>sa[i].c;
			sb[i].a=sa[i].a;
			sb[i].b=sa[i].b;
			sb[i].c=sa[i].c;
			sc[i].a=sa[i].a;
			sc[i].b=sa[i].b;
			sc[i].c=sa[i].c;
		}
		int sum1=0,sum2=0,sum3=0;
		sort(sa,sa+n,cmp1);
		for(int i=0;i<n/2;i++){
			sum1+=sa[i].a;
			sa[i].a=0;
			sa[i].b=0;
			sa[i].c=0;
		}
		for(int i=0;i<n;i++){
			sum1+=max(sa[i].b,sa[i].c);
		}
		sort(sb,sb+n,cmp2);
		for(int i=0;i<n/2;i++){
			sum2+=sb[i].b;
			sb[i].a=0;
			sb[i].b=0;
			sb[i].c=0;
		}
		for(int i=0;i<n;i++){
			sum2+=max(sb[i].a,sb[i].c);
		}
		sort(sc,sc+n,cmp3);
		for(int i=0;i<n/2;i++){
			sum3+=sc[i].c;
			sc[i].a=0;
			sc[i].b=0;
			sc[i].c=0;
		}
		for(int i=0;i<n;i++){
			sum3+=max(sc[i].a,sc[i].b);
		}
		cout<<max(sum1,max(sum2,sum3));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
