#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.in","r",stdin);
	int n,m;
	int a[114514111];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int df = 0;
	int chucun = 0,chucun1[114514];
	for(int i=1;i<=n;i++){
		chucun = 0;
		
		for(int j = n;j>=i;j--){
		df++;
			for(int z = i;z<j;z++){
				chucun+=a[z] |a[z+1];
			}
			if(chucun>=m){
				chucun1[df] = chucun-m;
			}else  chucun1[df] = m-chucun;
		}
	}
	sort(chucun1+1,chucun1+1+df	);
	cout<<m-chucun1[1];
	return 0;
}
