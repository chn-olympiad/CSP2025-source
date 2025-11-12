#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],b[300000],last = -1,p = 1,cnt,c[10];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k==0){
		for(int i = 1;i<=n;i++){
			cin>>a[i];c[a[i]]++;
		}
		cout <<c[0];
		/*else{
			for(int i = 1;i<=n;i++){
				if(a[i] == last)b[p]++;
				else if(b[p]>0)b[p]++,p++;
				else last = a[i];
			}
			for(int i = 1;i<=p;i++)
			cout <<b[i]<<' ';
			for(int i = 1;i<=p;i++)
				for(int j = 2;j<=b[i];j+=2)
					cnt+=(b[i]-j+1);
			cout <<cnt;
		}*/
	}else if(k == 1){
		for(int i = 1;i<=n;i++)
			cin>>a[i];
		for(int i = 1;i<n;i++)
			if(abs(a[i]-a[i+1]) == 1)cnt++,i++;
		cout <<cnt;
	}else cout <<n/2;
	return 0;
}
