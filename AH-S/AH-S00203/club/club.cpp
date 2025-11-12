#include<bits/stdc++.h>
using namespace std;
long long t,n;
long long ans,a_p[100010],b_p[100010],c_p[100010],cnt1,cnt2,cnt3,a[100010],b[100010],c[100010];
bool cmp1(long long x,long long y){
	long long maxn1 = max(b[x],c[x]),maxn2 = max(b[y],c[y]);
	return a[x] - maxn1 > a[y] - maxn2;
}bool cmp2(long long x,long long y){
	long long maxn1 = max(a[x],c[x]),maxn2 = max(a[y],c[y]);
	return b[x] - maxn1 > b[y] - maxn2;
}bool cmp3(long long x,long long y){
	long long maxn1 = max(b[x],a[x]),maxn2 = max(b[y],a[y]);
	return c[x] - maxn1 > c[y] - maxn2;
}bool cmp4(long long x,long long y){
		return a[x] > a[y];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){		
		bool flag = 1;							
		cin>>n;
		ans = cnt1 = cnt2 = cnt3 = 0;
		for(int i = 1;i <= n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i] > b[i]&&a[i] > c[i])
				a_p[++cnt1] = i;
			else if(b[i] > a[i]&&b[i] > c[i])
				b_p[++cnt2] = i;
			else
				c_p[++cnt3] = i;
			if(b[i] != 0&&c[i] != 0)	flag = 0;
		}if(flag){
				sort(a_p + 1,a_p + 1 + cnt1,cmp4);
				for(int i = 1;i <= n / 2;i++)
					ans += a[a_p[i]];
				cout<<ans<<endl;
				continue;
		}
		if(cnt1 > n / 2){
			sort(a_p + 1,a_p + 1 + cnt1,cmp1);
			for(int i = n / 2 + 1;i <= cnt1;i++)
				if(b[a_p[i]] > c[a_p[i]])
					b_p[++cnt2] = a_p[i];
				else
					c_p[++cnt3] = a_p[i];
			cnt1 = n / 2;
		}
		if(cnt2 > n / 2){
			sort(b_p + 1,b_p + 1 + cnt2,cmp2);
			for(int i = n / 2 + 1;i <= cnt2;i++)
				if(a[b_p[i]] > c[b_p[i]])
					a_p[++cnt1] = b_p[i];
				else
					c_p[++cnt3] = b_p[i];
			cnt2 = n / 2;		
		}
		if(cnt3 > n / 2){
			sort(c_p + 1,c_p + 1 + cnt3,cmp3);
			for(int i = n / 2 + 1;i <= cnt3;i++)
				if(a[c_p[i]] > b[c_p[i]])
					a_p[++cnt1] = c_p[i];
				else
					b_p[++cnt2] = c_p[i];
			cnt3 = n / 2;		
		}for(int i = 1;i <= cnt1;i++)
			ans += a[a_p[i]];
		for(int i = 1;i <= cnt2;i++)
			ans += b[b_p[i]];		
		for(int i = 1;i <= cnt3;i++)
			ans += c[c_p[i]];
		cout<<ans<<endl;
	}
	return 0;
}
