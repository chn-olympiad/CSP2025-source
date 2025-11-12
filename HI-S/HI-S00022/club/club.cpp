#include<bits/stdc++.h>
using namespace std;
int t,n,suma,sumb,mina,minb;int sum;int uu,oo;
struct tp {
	int al;
	int bl;
	int cl;
} a[100009];
int cmp(tp q,tp w){
	return q.al>w.al;
}int cmpp(tp q,tp w){
	return q.bl>w.bl;
}
int yan(){
	for(int i=1;i<=n;i++){
		if(a[i].bl!=0||a[i].cl!=0){
			return 0;
		}return 1;
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int tt=1;tt<=t;tt++) {
		suma=0;sumb=0;mina=0;minb=0;sum=0;uu=0;oo=0;
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>a[i].al;
			cin>>a[i].bl;
			cin>>a[i].cl;
		}if(yan()==1){//
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				suma+=a[i].al;
			}cout<<suma;continue;
		}//
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n/2;i++){
			suma+=a[i].al;
		}for(int i=n/2+1;i<=n;i++){
			sumb+=a[i].bl;
		}uu=suma+sumb;suma=0;sumb=0;  
		sort(a+1,a+n+1,cmpp);
		for(int i=1;i<=n/2;i++){
			suma+=a[i].bl;
		}for(int i=n/2+1;i<=n;i++){
			sumb+=a[i].al;
		}oo=suma+sumb;
		cout<<max(uu,oo);
	}
	return 0;
}
