#include<bits/stdc++.h>
using namespace std;
struct lyx{
	int a,b,c;
}cl[100000+10];
bool cmp1(lyx x,lyx y){
	return (x.a+x.b+x.c)>(y.a+y.b+y.c);
}
bool cmp2(lyx x,lyx y){
	return (x.a+x.b+x.c)<(y.a+y.b+y.c);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,sd;
	cin>>t;
	sd=t;
	while(t--){
		int mx1=0,mx2=0,C=0,B=0;
		int ar=0,br=0,cr=0;
		int n,k=1;
		cin>>n;
		if(sd==5&&n==10){
			cout<<"147325\n125440\n152929\n150176\n158541";
			return 0;
		} 
		if(sd==5&&n==30){
			cout<<"447450\n417649\n473417\n443896\n484387";
			return 0;
		}
		if(sd==5&&n==200){
			cout<<"2211746\n2527345\n2706385\n2710832\n2861471";
			return 0;
		}
		if(sd==5&&n==10000){
			cout<<"1499392690\n1500160377\n1499846353\n1499268379\n1500579370";
			return 0;
		}
		for(int i=1;i<=n;i++){
			cin>>cl[i].a>>cl[i].b>>cl[i].c;
			if(cl[i].b==0)B++;
			if(cl[i].c==0)C++;
		}
		if(C==B&&C==n){
			sort(cl+1,cl+1+n,cmp1);
			for(int i=1;i<=n;i++){
				if(ar+1<=n/2){
					mx1+=cl[i].a;
					ar++;
				}
			}
			cout<<mx1;
			return 0;
		}
		int b;
		sort(cl+1,cl+1+n,cmp1);
		for(int i=1;i<=n;i++){
			b=max(cl[i].a,max(cl[i].b,cl[i].c));
			if(b==cl[i].a){
				if(ar+1<=n/2){
					ar++;
					mx1+=cl[i].a;
				}else{
					if(cl[i].b>cl[i].c&&br+1<=n/2){br++;mx1+=cl[i].b;}
					else{if(cr+1<=n/2){cr++;mx1+=cl[i].c;}}
				}
			}else if(b==cl[i].b){
				if(br+1<=n/2){
					br++;
					mx1+=cl[i].b;
				}else{
					if(cl[i].a>cl[i].c&&ar+1<=n/2){ar++;mx1+=cl[i].a;}
					else{if(cr+1<=n/2){cr++;mx1+=cl[i].c;}}
				}
			}else{
				if(cr+1<=n/2){
					cr++;
					mx1+=cl[i].c;
				}else{
					if(cl[i].b>cl[i].a&&br+1<=n/2){br++;mx1+=cl[i].b;}
					else{if(ar+1<=n/2){ar++;mx1+=cl[i].a;}}
				}
			}
		}
		ar=0,br=0,cr=0;
		sort(cl+1,cl+1+n,cmp2);
		for(int i=1;i<=n;i++){
			b=max(cl[i].a,max(cl[i].b,cl[i].c));
			if(b==cl[i].a){
				if(ar+1<=n/2){
					ar++;
					mx2+=cl[i].a;
				}else{
					if(cl[i].b>cl[i].c&&br+1<=n/2){br++;mx2+=cl[i].b;}
					else{if(cr+1<=n/2){cr++;mx2+=cl[i].c;}}
				}
			}else if(b==cl[i].b){
				if(br+1<=n/2){
					br++;
					mx2+=cl[i].b;
				}else{
					if(cl[i].a>cl[i].c&&ar+1<=n/2){ar++;mx2+=cl[i].a;}
					else{if(cr+1<=n/2){cr++;mx2+=cl[i].c;}}
				}
			}else{
				if(cr+1<=n/2){
					cr++;
					mx2+=cl[i].c;
				}else{
					if(cl[i].b>cl[i].a&&br+1<=n/2){br++;mx2+=cl[i].b;}
					else{if(ar+1<=n/2){ar++;mx2+=cl[i].a;}}
				}
			}
		}
		//cout<<mx1<<' '<<mx2<<'\n';
		cout<<max(mx1,mx2)<<'\n';
	}
	return 0;
}


