#include <bits/stdc++.h>
using namespace std;
int n,a[10050][3],s[4],m[3],b[10050];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int ans[t];
	for(int u=0;u<t;++u){
		cin>>n;
		for(int i=0;i<n;++i)
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		//第一组
		for(int i=0;i<n;++i){
			for(int q=1;q<n;++q){
				if(a[q][0]>a[q-1][0]){
					swap(a[q][0],a[q-1][0]);
					swap(a[q][1],a[q-1][1]);
					swap(a[q][2],a[q-1][2]);
				}
			}
		}
		for(int i=0;i<n;++i){
			if(i<n/2)
				s[0]+=a[i][0];
			else
				s[0]+=max(a[i][1],a[i][2]);
		}
		//第二组
		for(int i=0;i<n;++i){
			for(int q=1;q<n;++q){
				if(a[q][1]>a[q-1][1]){
					swap(a[q][0],a[q-1][0]);
					swap(a[q][1],a[q-1][1]);
					swap(a[q][2],a[q-1][2]);
				}
			}
		}
		for(int i=0;i<n;++i){
			if(i<n/2)
				s[1]+=a[i][1];
			else
				s[1]+=max(a[i][0],a[i][2]);
		}
		//第三组
		for(int i=0;i<n;++i){
			for(int q=1;q<n;++q){
				if(a[q][2]>a[q-1][2]){
					swap(a[q][0],a[q-1][0]);
					swap(a[q][1],a[q-1][1]);
					swap(a[q][2],a[q-1][2]);
				}
			}
		}
		for(int i=0;i<n;++i){
			if(i<n/2)
				s[2]+=a[i][2];
			else
				s[2]+=max(a[i][1],a[i][0]);
		}
		//第四组
		for(int i=0;i<n;++i){
			if(a[i][0]>a[i][1]&&a[i][0]>a[i][2])
				m[0]++;
			else if(a[i][1]>a[i][0]&&a[i][1]>a[i][2])
				m[1]++;
			else if(a[i][2]>a[i][0]&&a[i][2]>a[i][1])
				m[2]++;
		}
		if(m[0]<=n/2&&m[1]<=n/2&&m[2]<=n/2){
			for(int i=0;i<n;++i)
				s[3]+=max(a[i][0],max(a[i][1],a[i][2]));
		}
		ans[u]=max(s[3],max(max(s[0],s[1]),s[2]));
		s[0]=0;
		s[1]=0;
		s[2]=0;
		s[3]=0;
		m[0]=0;
		m[1]=0;
		m[2]=0;
		for(int i=0;i<n;++i)
			b[i]=0;
	}
	for(int i=0;i<t;++i){
        cout<<ans[i]<<'\n';
	}
	return 0;
}
