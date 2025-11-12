#include <bits/stdc++.h>
using namespace std;

int xiabiao(int s[])
{
	int xb,zd;
	if(s[1] > s[0]){
		zd = s[1];
		xb = 1;
	}else{
		zd = s[0];
		xb = 0;
	}
	if(s[2] > zd){
		return 2;
	}else{
		return xb;
	}
}

int mid(int s[] , int xb) 
{
	switch(xb){
		case(0):return s[0] - max(s[1],s[2]);
		case(1):return s[1] - max(s[0],s[2]);
		case(2):return s[2] - max(s[0],s[1]);
	}
	return 0;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T,n;
	cin>>T;
	while(T--){
		cin>>n;
		int a[n][3];
		int x[3] = {0};
		int xb[n];
		long long ans = 0;
		for(int i=0; i<n; i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			xb[i]= xiabiao(a[i]);
			x[ xb[i] ]++;
			ans+=a[i][xb[i]];
		}
		int xmax = xiabiao(x);
		int midd[x[xmax]] = {0};
		if(x[xmax] > (n/2) ){
			
			
			int dozo = 0;
			for(int j=0; j<n; j++){
				if(xb[j] == xmax){
					midd[dozo] = mid(a[j],xmax);
					dozo ++;
				}
			}
			sort(midd, midd + x[xmax]);
			int tm = 0; 
			while (x[xmax] > (n / 2))
			{
				x[xmax]--;
				ans -= midd[tm];
				tm++;
			}
		}
		
		cout<<ans<<endl;

	}
	return 0;
}
