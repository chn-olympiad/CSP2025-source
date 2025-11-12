#include<bits/stdc++.h>
#define int long long
#define r0 return 0;
#define str string
using namespace std;
const int N=1e6+5;
//yinggaishistring,danshiwanglezaxiele~
int s,a[N],maxn=LLONG_MIN,minn=LLONG_MAX;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;int d=s;if(s<10)cout<<s;
	if(s>=10&&s<100){
		int g=s%10,shi=s/10;
		maxn=max(g,shi);minn=min(g,shi);cout<<maxn<<minn;
	}if(s>=100){
		int g=s%10,shi=s/10%10,bai=s/100;
		maxn=max(maxn,g);maxn=max(maxn,shi);maxn=max(maxn,bai);
		minn=min(minn,g);minn=min(minn,shi);minn=min(minn,bai);
		if(maxn!=g&&minn!=g)cout<<maxn<<g<<minn<<'\n';
		if(maxn!=shi&&minn!=shi)cout<<maxn<<shi<<minn<<'\n';
		if(maxn!=bai&&minn!=bai)cout<<maxn<<bai<<minn<<'\n';
	}
	r0
}//zhinengde8fenle,stringwangjizaxiele qwq~~kenengyaofei,stringbuhuixiele
