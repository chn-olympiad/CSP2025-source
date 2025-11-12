#include<bits/stdc++.h>
using namespace std;
#define elif else if
#define int long long
const int N=1e5+10;
int n,cnta,cntb,cntc,ans,midn;
struct node{
	int a,b,c;
	int choise;
}a[N];
int max(int a,int b,int c){
	return (a>b?a:b)>c?(a>b?a:b):c;
}
int min(int a,int b,int c){
	return min(min(a,b),c);
}
bool cmp(node a,node b){
	return max(a.a,a.b,a.c)>max(b.a,b.b,b.c);
}
void work2(){
	freopen("D:/club/club1.in","r",stdin);
	cin>>n;
	int maxs = 0;
	for(int i = 0;i<n;i++){
		cin>>a[i].a>>a[i].b>>a[i].c;
		maxs+=a[i].a;
		a[i].choise=1;
	}
	bool dos = 1;
	while(dos){
		a[0].choise++;
		int k = 0;
		while(a[k].choise == 4){
			a[k].choise = 1;
			k++;
			a[k].choise++;
			if(k == n-1 && a[k].choise == 3){
				dos=0;
			}
		}
		int ans = 0;
		cnta=0;cntb=0;cntc=0;ans=0;midn=n/2;
		for(int i = 0;i<n;i++){
//			cout<<a[k].choise<<"+";
			if(a[k].choise == 1){
				if(cnta>=midn) break;
				cnta++;
				ans+=a[i].a;
			}
			elif(a[k].choise == 2){
				if(cntb>=midn) break;
				cntb++;
				ans+=a[i].b;
			}
			else{
				if(cntc>=midn) break;
				cntc++;
				ans+=a[i].c;
			}
		}
//		cout<<"="<<ans<<endl;
		maxs = max(maxs,ans);
	}
	cout<<maxs<<endl;
}
void work(){
	cin>>n;
	cnta=0;cntb=0;cntc=0;ans=0;midn=n/2;
	for(int i = 0;i<n;i++){
		cin>>a[i].a>>a[i].b>>a[i].c;
	}
	sort(a,a+n,cmp);
	for(int i = 0;i<n;i++){
		int maxs = max(a[i].a,a[i].b,a[i].c);
		int y=min(a[i].a,a[i].b,a[i].c);
		int x;
		if(a[i].a != maxs && a[i].a != y){
			x=a[i].a;
		}
		elif(a[i].b != maxs && a[i].b != y){
			x=a[i].b;
		}
		elif(a[i].c != maxs && a[i].c != y){
			x=a[i].c;
		}
		tag:
		if(maxs == a[i].a && cnta<midn){
			ans+=maxs;
			cnta++;
		}
		elif(maxs == a[i].b && cntb<midn){
			ans+=maxs;
			cntb++;
		}
		elif(maxs == a[i].c && cntc<midn){
			ans+=maxs;
			cntc++;
		}
		else{
			if(maxs == x){
				maxs = y;
			}
			else{
				maxs=x;
			}
			goto tag;
		}
	}
	cout<<ans<<endl;
}
signed main(){
//	freopen("D:/club/club1.in","r",stdin);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		work();
	}
	return 0;
}
/*
//0pts..........
cin>>n;
	int maxs = 0;
	for(int i = 0;i<n;i++){
		cin>>a[i].a>>a[i].b>>a[i].c;
		maxs+=a[i].a;
		a[i].choise=1;
	}
	bool dos = 1;
	while(dos){
		a[0].choise++;
		int k = 0;
		while(a[k].choise == 4){
			a[k].choise = 1;
			k++;
			a[k].choise++;
			if(k == n-1 && a[k].choise == 3){
				dos=0;
			}
		}
		int ans = 0;
		cnta=0;cntb=0;cntc=0;ans=0;midn=n/2;
		for(int i = 0;i<n;i++){
			cout<<a[k].choise<<"+";
			if(a[k].choise == 1){
				if(cnta>=midn) break;
				cnta++;
				ans+=a[i].a;
			}
			elif(a[k].choise == 2){
				if(cntb>=midn) break;
				cntb++;
				ans+=a[i].b;
			}
			else{
				if(cntc>=midn) break;
				cntc++;
				ans+=a[i].c;
			}
		}
		cout<<"="<<ans<<endl;
		maxs = max(maxs,ans);
	}
	cout<<maxs<<endl;
*/
