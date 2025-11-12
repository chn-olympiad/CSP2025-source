#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,T,A=0,B=0,C=0,club_n[4];
ll ans=0;
struct aij{
	int a1,a2,a3;
}a[100005];
struct pred{
	int choz,chon,c;
}pd[100005];
int cmpa(aij aij1,aij aij2){
	return aij1.a1>aij2.a1;
}
int cmpc(pred p1,pred p2){
	return p1.c>p2.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		ans=0;
		A=1;
		B=1;
		for(int i=0;i<4;i++){
			club_n[i]=0;
		}
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			pd[i].choz=max(max(a[i].a1,a[i].a2),a[i].a3);
			ans+=pd[i].choz;
			if(pd[i].choz==a[i].a1){
				pd[i].chon=1;
				pd[i].c=max(a[i].a2-pd[i].choz,a[i].a3-pd[i].choz);
			}
			else if(pd[i].choz==a[i].a2){
				pd[i].chon=2;
				pd[i].c=max(a[i].a1-pd[i].choz,a[i].a3-pd[i].choz);
			}
			else if(pd[i].choz==a[i].a3){
				pd[i].chon=3;
				pd[i].c=max(a[i].a1-pd[i].choz,a[i].a2-pd[i].choz);
			}
			club_n[pd[i].chon]++;
			
			if(a[i].a2!=0||a[i].a3!=0){
				A=0;
			}
		}
		
		
		//AAAAAAAAAA
		if(A==1){
			ll ansA=0;
			sort(a,a+n,cmpa);
			for(int i=0;i<n/2;i++){
				ansA+=a[i].a1;
			}
			ans=ansA;
		}
		
		//CCCCCCCCCC
		else{
			if(club_n[1]>n/2||club_n[2]>n/2||club_n[3]>n/2){
				sort(pd,pd+n,cmpc);
				int cn=max(club_n[1],max(club_n[2],club_n[3]))-n/2,cd=0;
				if(club_n[1]>n/2)cd=1;
				else if(club_n[2]>n/2)cd=2;
				else if(club_n[3]>n/2)cd=3;
				for(int i=0;i<n;i++){
					if(pd[i].chon==cd){
						ans+=pd[i].c;
						cn--;
					}
					if(cn==0)break;
				}
			}
		}



		cout<<ans<<"\n";
	}
	return 0;
}
