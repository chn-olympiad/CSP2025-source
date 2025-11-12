#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;

int t,n,hn,a,b,c,ans,acnt,bcnt,ccnt,ax[N],bx[N],cx[N];

void push(int type,int aa,int bb,int cc){
	if(type==0){
		ans+=aa;
		ax[++acnt]=max(bb-aa,cc-aa);
	}else if(type==1){
		ans+=bb;
		bx[++bcnt]=max(aa-bb,cc-bb);
	}else{
		ans+=cc;
		cx[++ccnt]=max(aa-cc,bb-cc);
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=acnt=bcnt=ccnt=0;
		cin>>n;
		hn=(n>>1);
		for(int i=1;i<=n;i++){
			cin>>a>>b>>c;
			if(a>b){
				if(a>c)push(0,a,b,c);
				else push(2,a,b,c);
			}else if(b>c){
				push(1,a,b,c);
			}else{
				push(2,a,b,c);
			}
		}
		if(acnt>hn){
			sort(ax+1,ax+1+acnt);
			for(int i=acnt;i>hn;i--){
				ans+=ax[i];
			}
		}else if(bcnt>hn){
			sort(bx+1,bx+1+bcnt);
			for(int i=bcnt;i>hn;i--){
				ans+=bx[i];
			}
		}else if(ccnt>hn){
			sort(cx+1,cx+1+ccnt);
			for(int i=ccnt;i>hn;i--){
				ans+=cx[i];
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
