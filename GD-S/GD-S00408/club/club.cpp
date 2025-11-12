#include <bits/stdc++.h>
using namespace std;
#define pr pair<long long,long long>
#define mp make_pair
#define axx maxx(a[i],b[i],c[i])
#define sec secd(a[i],b[i],c[i])
#define laa minn(a[i],b[i],c[i])
const long long INF=0x3f3f3f3f3f3f3f3f;
long long maxx(long long a,long long b,long long c){
	return max(a,max(b,c));
}
long long minn(long long a,long long b,long long c){
	return min(a,min(b,c));
}
long long secd(long long a,long long b,long long c){
	return a+b+c-maxx(a,b,c)-minn(a,b,c);
}
priority_queue<pr,vector<pr>,greater<pr> >q[5];
long long n;
long long a[100005],b[100005],c[100005];
long long ans=0;
void cza(){
	while(1){
		if(q[1].size()<=n/2) break;
		long long mqz=q[1].top().first,mqb=q[1].top().second;
		long long i=mqb;
		if(a[i]==axx){
			if(b[i]==sec){
		    	q[2].push(mp(sec-laa,i));
		    	q[1].pop();
		    	ans-=(axx-sec);
		    }
		    else if(c[i]==sec){
		    	q[3].push(mp(sec-laa,i));
		    	q[1].pop();
	    		ans-=(axx-sec);
	    	}
		}
		else if(a[i]==sec){
			if(b[i]==laa){
		    	q[2].push(mp(INF,i));
		    	q[1].pop();
		    	ans-=(sec-laa);
		    }
		    else if(c[i]==laa){
		    	q[3].push(mp(INF,i));
		    	q[1].pop();
	    		ans-=(sec-laa);
	    	}
		}	
	}
}
void czb(){
	while(1){
		if(q[2].size()<=n/2) break;
		long long mqz=q[2].top().first,mqb=q[2].top().second;
		long long i=mqb;
		if(b[i]==axx){
			if(a[i]==sec){
		    	q[1].push(mp(sec-laa,i));
		    	q[2].pop();
		    	ans-=(axx-sec);
		    }
		    else if(c[i]==sec){
		    	q[3].push(mp(sec-laa,i));
		    	q[2].pop();
	    		ans-=(axx-sec);
	    	}
		}
		else if(b[i]==sec){
			if(a[i]==laa){
		    	q[1].push(mp(INF,i));
		    	q[2].pop();
		    	ans-=(sec-laa);
		    }
		    else if(c[i]==laa){
		    	q[3].push(mp(INF,i));
		    	q[2].pop();
	    		ans-=(sec-laa);
	    	}
		}	
	}
}
void czc(){
	while(1){
		if(q[3].size()<=n/2) break;
		long long mqz=q[3].top().first,mqb=q[3].top().second;
		long long i=mqb;
		if(c[i]==axx){
			if(a[i]==sec){
		    	q[1].push(mp(sec-laa,i));
		    	q[3].pop();
		    	ans-=(axx-sec);
		    }
		    else if(b[i]==sec){
		    	q[2].push(mp(sec-laa,i));
		    	q[3].pop();
	    		ans-=(axx-sec);
	    	}
		}
		else if(c[i]==sec){
			if(a[i]==laa){
		    	q[1].push(mp(INF,i));
		    	q[3].pop();
		    	ans-=(sec-laa);
		    }
		    else if(b[i]==laa){
		    	q[2].push(mp(INF,i));
		    	q[3].pop();
	    		ans-=(sec-laa);
	    	}
		}	
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t;
	scanf("%lld",&t);
	while(t--){
		while(!q[1].empty()) q[1].pop();
		while(!q[2].empty()) q[2].pop();
		while(!q[3].empty()) q[3].pop();
		ans=0;
		scanf("%lld",&n);
	    for(long long i=1;i<=n;i++){
	    	scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
	    	ans+=maxx(a[i],b[i],c[i]);
	    } 
	    for(long long i=1;i<=n;i++){
	    	if(a[i]>=b[i]&&a[i]>=c[i]) q[1].push(mp(axx-sec,i));
	    	else if(b[i]>=a[i]&&b[i]>=c[i]) q[2].push(mp(axx-sec,i));
	    	else if(c[i]>=b[i]&&c[i]>=a[i]) q[3].push(mp(axx-sec,i));
	    }
    	cza();
		czb();
		czc();
	    printf("%lld\n",ans);
	}
	
    return 0;
} 
/*
in:
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
/*
out:
18
4
13
*/
