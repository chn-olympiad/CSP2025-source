#include<bits/stdc++.h>
using namespace std;
struct member{
	int a,b,c;
	bool k=false;
	int best,worst;
	char most,least;
};
bool cmp(member a,member b){
	if(a.k){
		return false;
	}if(b.k){
		return true;
	}
	if(a.worst==0 && b.worst==0){
		if(a.best>=b.best)
			return true;
	}else{
		if(a.best-a.worst>=b.best-b.worst)
			return true;
	}
	return false;
	
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t,n,w1,w2,w3,z,z1;
	cin>>t;
	while(t--){
		z=0;
		z1=0;
		cin>>n;
		member a[n];
		for(int i=0;i<n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			a[i].best=max(max(a[i].a,a[i].b),a[i].c);
			if(a[i].best==a[i].a)
				a[i].most='a';
			else if(a[i].best==a[i].b)
				a[i].most='b';
			else if(a[i].best==a[i].c)
				a[i].most='c';
			if(a[i].a<=a[i].b && a[i].a<=a[i].c){
				a[i].worst=a[i].a;
				a[i].least='a';
			}else if(a[i].b<=a[i].a && a[i].b<=a[i].c){
				a[i].worst=a[i].b;
				a[i].least='b';
			}else if(a[i].c<=a[i].a && a[i].c<=a[i].b){
				a[i].worst=a[i].b;
				a[i].least='c';
			}
		}
		
		w1=n/2;
		w2=n/2;
		w3=n/2;
		sort(a,a+n,cmp);
		for(int i=0;i<n;i++){
			if(a[i].most=='a' && w1!=0){
				a[i].k=true;
				z+=a[i].best;
				a[i].a=-1;
				w1--;
				a[i].best=max(a[i].b,a[i].c);
				if(a[i].best==a[i].b)
					a[i].most='b';
				else
					a[i].most='c';
				z1++;
			}else if(a[i].most=='b' && w2!=0){
				a[i].k=true;
				z+=a[i].best;
				a[i].b=-1;
				w2--;
				a[i].best=max(a[i].a,a[i].c);
				if(a[i].best==a[i].a)
					a[i].most='a';
				else
					a[i].most='c';
				z1++;
			}else if(a[i].most=='c' && w3!=0){
				a[i].k=true;
				z+=a[i].best;
				a[i].c=-1;
				w3--;
				a[i].best=max(a[i].b,a[i].a);
				if(a[i].best==a[i].b)
					a[i].most='b';
				else
					a[i].most='a';
				z1++;
			}
		}
		if(z1==n){
			cout<<z<<"\n";
			continue;
		}
		if(w1==0){
			for(int i=0;i<n;i++){
				a[i].a=-1;
				a[i].best=max(a[i].b,a[i].c);
				if(a[i].best==a[i].b)
					a[i].most='b';
				else
					a[i].most='c';
			}
		}if(w2==0){
			for(int i=0;i<n;i++){
				a[i].b=-1;
				a[i].best=max(a[i].a,a[i].c);
				if(a[i].best==a[i].a)
					a[i].most='a';
				else
					a[i].most='c';
			}
		}if(w3==0){
			for(int i=0;i<n;i++){
				a[i].c=-1;
				a[i].best=max(a[i].a,a[i].b);
				if(a[i].best==a[i].b)
					a[i].most='b';
				else
					a[i].most='a';
			}
		}
		
		sort(a,a+n,cmp);
		for(int i=0;i<n;i++){
			if(a[i].most=='a' && w1!=0 && !a[i].k){
				a[i].k=true;
				z+=a[i].best;
				a[i].a=-1;
				w1--;
				z1++;
			}else if(a[i].most=='b' && w2!=0 && !a[i].k){
				a[i].k=true;
				z+=a[i].best;
				a[i].b=-1;
				w2--;
				z1++;
			}else if(a[i].most=='c' && w3!=0 && !a[i].k){
				a[i].k=true;
				z+=a[i].best;
				a[i].c=-1;
				w3--;
				z1++;
			}
		}
		cout<<z<<"\n";
	}
	return 0;
}
