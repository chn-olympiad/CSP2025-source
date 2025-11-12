#include<bits/stdc++.h>
using namespace std;

int T;
int n;
struct peo{
	int a,b,c,d;
}a[100005];

bool cmdA(peo a,peo b){
	return a.a>b.a;
}
bool cmdB(peo a,peo b){
	return a.d>b.d;
}





bool flagA=1,flagB=1;

void solve_A(){
	int ans=0;
	sort(a+1,a+n+1,cmdA);
	for(int i=1;i<=n/2;i++){
		ans+=a[i].a;
	}cout<<ans<<"\n";
	return;
}
void solve_B(){
	int ans=0;
	sort(a+1,a+n+1,cmdB);
	for(int i=1;i<=n/2;i++){
		ans+=a[i].a;
	}for(int i=n/2+1;i<=n;i++){
		ans+=a[i].b;
	}
	cout<<ans<<"\n";
}

bool cmdC(peo a,peo b){
	return max(a.a,max(a.b,a.c))>max(b.a,max(b.b,b.c));
}
bool mxA(peo a,peo b){
	return a.a-max(a.b,a.c)>b.a-max(b.b,b.c);
}
bool mxB(peo a,peo b){
	return a.b-max(a.a,a.c)>b.b-max(b.a,b.c);
}
bool mxC(peo a,peo b){
	return a.c-max(a.b,a.a)>b.c-max(b.b,b.a);
}

void solve(){
	int A,B,C;
	int ans=0;
	A=B=C=n/2;
	sort(a+1,a+n+1,mxA); 
	for(int i=1;i<=n;i++){
		if(a[i].a-max(a[i].b,a[i].c)>0){
			if(A){
				ans+=a[i].a;
				a[i].a=a[i].b=a[i].c=0;
				A--;
			}else{
				a[i].a=0;
			}
		}else{
			break;
		}
	}
	sort(a+1,a+n+1,mxB); 
	for(int i=1;i<=n;i++){
		if(a[i].b-max(a[i].a,a[i].c)>0){
			if(B){
				ans+=a[i].b;
				a[i].a=a[i].b=a[i].c=0;
				B--;
			}else{
				a[i].b=0;
			}
		}else{
			break;
		}
	}sort(a+1,a+n+1,mxC); 
	for(int i=1;i<=n;i++){
		if(a[i].c-max(a[i].a,a[i].b)>0){
			if(C){
				ans+=a[i].c;
				a[i].a=a[i].b=a[i].c=0;
				C--;
			}else{
				a[i].c=0;
			}
		}else{
			break;
		}
	}sort(a+1,a+n+1,cmdC);
	for(int i=1;i<=n;i++){
		int mx=max(a[i].a,max(a[i].b,a[i].c));
		if(mx==a[i].a and A){
			A--;
			ans+=a[i].a;
		}else if(mx==a[i].b and B){
			B--;
			ans+=a[i].b;
		}else if(mx==a[i].c and C){
			C--;
			ans+=a[i].c;
		}
	}cout<<ans<<"\n";
	return;
}


int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			a[i].d=a[i].a-max(a[i].b,a[i].c);
			if(a[i].b!=0 or a[i].c!=0){
				flagA=0;
			}if(a[i].c!=0){
				flagB=0;
			}
		}if(flagA){
			solve_A();
		}else if(flagB){
			solve_B();
		}else{
			solve();
		}
	}
	
	
	
	
	
	
	
	return 0;
} 
