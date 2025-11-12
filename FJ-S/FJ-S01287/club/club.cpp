#include <bits/stdc++.h>
using namespace std;
struct p1{
	long long l;
	int num;
}ps1[100005];
struct p2{
	long long l;
	int num;
}ps2[100005];
struct p3{
	long long l;
	int num;
}ps3[100005];
struct all{
	long long _1,_2,_3;
	bool flag;
}alls[100005];
int t,n;

bool cmp1(p1 a,p1 b){
	return a.l<b.l;
}
bool cmp2(p2 a,p2 b){
	return a.l<b.l;
}
bool cmp3(p3 a,p3 b){
	return a.l<b.l;
}

int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--){
		cin>>n;
		int part1=0,part2=0,part3=0,cnt1=0,cnt2=0,cnt3=0;
		for(int i=1;i<=n;i++){
			cin>>ps1[i].l>>ps2[i].l>>ps3[i].l;
			ps1[i].num=ps2[i].num=ps3[i].num=i;
			alls[i].flag=0;
			if(ps1[i].l>=ps2[i].l && ps1[i].l>=ps3[i].l){
				alls[i]._1=1;
			}else if(ps2[i].l>=ps1[i].l && ps2[i].l>=ps3[i].l){
				alls[i]._1=2;
			}else if(ps3[i].l>=ps1[i].l && ps3[i].l>=ps2[i].l){
				alls[i]._1=3;
			}
			if(ps1[i].l<=ps2[i].l && ps1[i].l<=ps3[i].l){
				if(alls[i]._1!=1) alls[i]._3=1;
			}else if(ps2[i].l<=ps1[i].l && ps2[i].l<=ps3[i].l){
				if(alls[i]._1!=2) alls[i]._3=2;
			}else if(ps3[i].l<=ps1[i].l && ps3[i].l<=ps2[i].l){
				if(alls[i]._1!=3) alls[i]._3=3;
			}
			alls[i]._2=6-alls[i]._1-alls[i]._3;
		}
		sort(ps1+1,ps1+1+n,cmp1);
		sort(ps2+1,ps2+1+n,cmp2);
		sort(ps3+1,ps3+1+n,cmp3);
		for(int i=n;i>=1;i--){
			if(!alls[i].flag){
				if(cnt1<n/2)
					if(alls[ps1[i].num]._1==1 && !alls[ps1[i].num].flag){
						part1+=ps1[i].l;
						cnt1++;
						alls[ps1[i].num].flag=1;
					}
				if(cnt2<n/2)
					if(alls[ps2[i].num]._1==2 && !alls[ps2[i].num].flag){
						part2+=ps2[i].l;
						cnt2++;
						alls[ps2[i].num].flag=1;
					}
				if(cnt3<n/2)
					if(alls[ps3[i].num]._1==3 && !alls[ps3[i].num].flag){
						part3+=ps3[i].l;
						cnt3++;
						alls[ps3[i].num].flag=1;
					}
				if(cnt1<n/2)
					if(alls[ps1[i].num]._2==1 && !alls[ps1[i].num].flag){
						part1+=ps1[i].l;
						cnt1++;
						alls[ps1[i].num].flag=1;
					}
				if(cnt2<n/2)
					if(alls[ps2[i].num]._2==2 && !alls[ps2[i].num].flag){
						part2+=ps2[i].l;
						cnt2++;
						alls[ps2[i].num].flag=1;
					}
				if(cnt3<n/2)
					if(alls[ps3[i].num]._2==3 && !alls[ps3[i].num].flag){
						part3+=ps3[i].l;
						cnt3++;
						alls[ps3[i].num].flag=1;
					}
				if(cnt1<n/2)
					if(alls[ps1[i].num]._3==1 && !alls[ps1[i].num].flag){
						part1+=ps1[i].l;
						cnt1++;
						alls[ps1[i].num].flag=1;
					}
				if(cnt2<n/2)
					if(alls[ps2[i].num]._3==2 && !alls[ps2[i].num].flag){
						part2+=ps2[i].l;
						cnt2++;
						alls[ps2[i].num].flag=1;
					}
				if(cnt3<n/2)
					if(alls[ps3[i].num]._3==3 && !alls[ps3[i].num].flag){
						part3+=ps3[i].l;
						cnt3++;
						alls[ps3[i].num].flag=1;
					}
			}
		}
		cout<<part1<<' '<<part2<<' '<<part3<<endl;
		cout<<part1+part2+part3<<endl;
	}
	return 0;
}








