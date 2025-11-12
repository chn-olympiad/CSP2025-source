#include<bits/stdc++.h>
using namespace std;
int n,t;
int a[100005]={0};

struct student{
	int a,b,c;
	int fi,se,th;
}; 
student s[100005];

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int i=1;i<=t;i++){
		cin >> n;
		for(int j=1;j<=n;j++){
			for(int z=1;z<=3;z++){
				cin >> a[z];
				if(z==1)
				s[j].a=a[1];
				if(z==2)
				s[j].b=a[2];
				if(z==3){
				s[j].c=a[3];
				sort(a+1,a+4,cmp);
				s[j].fi=a[1];
				s[j].se=a[2];
				s[j].th=a[3];
		        }
			}
		}
		long long tot=0; 
		int x=1;
		int d=0,e=0,f=0;
		while(x<=n){
			if(s[x].fi=s[x].a)
			d++;
			if(s[x].fi=s[x].b)
			e++;
			if(s[x].fi=s[x].c)
			f++;
			if(d<=n/2 || e<=n/2 || f<=n/2){
			tot+=s[x].fi;
			x++;
		    }else{
			if(s[x].se=s[x].a)
			d++;
			if(s[x].se=s[x].b)
			e++;
			if(s[x].se=s[x].c)
			f++;
			tot+=s[x].se;
			x++;
		    }
		}
		cout << tot << endl;
	}
	return 0;
}
