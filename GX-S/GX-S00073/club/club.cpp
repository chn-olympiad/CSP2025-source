#include<bits/stdc++.h>
using namespace std;
long long ans=0;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int p;
    cin>>p;
    int kkf=0;
    for(int pri=1;pri<=p;pri++){
	    ans=0;
    int fp=0,sp=0,tp=0;
    int poe=0;
    kkf=0;
    		int max=-1430;
    long long f[654321];
		long long n;
		cin>>n;
		//
		for(int uu=1;uu<=n;uu++){
		cin>>f[uu]>>f[uu+n]>>f[uu+n*2];
		}
		//
				long long k1,k2;
		if(f[n+2]==f[n+3]&&f[n+2]==f[n+4]&&f[n*2]==f[n*2+1]&&f[n+4]==f[n*2]&&f[n*2+2]==f[n*2+3]&&f[n+3]==0){
		for(int uu=1;uu<=n;uu++){
			k1+=f[uu];
		}
		for(int uu=1;uu<=n*3;uu++){
			k2+=f[uu];
		}
		if(k1==k2){
		sort(f,f+n*3+1);
		for(int kk=1;kk<=n/2;kk++){
			ans+=f[n*3-kk+1];
		}
		cout<<ans<<endl;
		continue;
	}
}
while(poe<=n){
				if(fp>=n/2){
			for(int kk=1;kk<=n;kk++){
				f[kk]=-1;
			}
		}
		if(sp>=n/2){
			for(int kk=n+1;kk<=n+n;kk++){
				f[kk]=-1;}
			}
		if(tp>=n/2){
			for(int kk=n*2+1;kk<=3*n;kk++){
				f[kk]=-1;
			}
		}
		for(int uu=1;uu<=n*3;uu++){
			if(f[uu]>=max){
			max=f[uu];
			kkf=uu;
		}
	}
	f[kkf]=-1;
		if(kkf<=n){
		fp++;
	}
			if(kkf>n&&kkf<=n*2){
		sp++;
	}
			if(kkf>n*2){
		tp++;
	}
	//
	if(kkf<=n){
		ans+=max;
		poe++;
		max=0;
		for(int uu=kkf;uu<=n*3;uu+=n){
			f[uu]=-1;
		}
		continue;
	}
		if(kkf>n&&kkf<=n*2){
		ans+=max;
		poe++;
		max=0;
		for(int uu=kkf-n;uu<=n*3;uu+=n){
			f[uu]=-1;
		}
		continue;
}
		if(kkf>n*2){
		ans+=max;
		poe++;
		max=0;
				for(int uu=kkf-n*2;uu<=n*3;uu+=n){
			f[uu]=-1;
		}
		continue;
	}
	//
	}
	cout<<ans<<endl;
}
return 0;
}
