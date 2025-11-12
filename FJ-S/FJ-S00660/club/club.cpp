#include <bits/stdc++.h>
using namespace std;
int t,n,ans;
struct node{
	int a,b,c;
}a[100010];
bool cmp(node a,node b){
	return a.a > b.a;
}
bool cmp_2(node a,node b){
	return a.b > b.b;
}
bool cmp_3(node a,node b){
	return a.c > b.c;
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
		}
		sort(a+1,a+n+1,cmp);
		sort(a+1,a+n+1,cmp_2);
		sort(a+1,a+n+1,cmp_3);
		int tmp=0;
		for(int i=1;i<=3;i++){
			for(int j=1;j<=n/2;j++){
				if(tmp<=n&&i==1&&a[i].a!=0){
			        ans+=a[i].a;
			        tmp++;
			    }  
				if(tmp<=n&&i==2&&a[i].b!=0){
			        ans+=a[i].b;
			        tmp++;
			    }  
				if(tmp<=n&&i==2&&a[i].c!=0){
			        ans+=a[i].c;
			        tmp++;
			    }    	
		    }
	    }
	    cout<<ans<<endl;
	}

	return 0;
}
