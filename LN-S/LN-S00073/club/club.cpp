#include<bits/stdc++.h>
using namespace std;
long long a1[100002],a2[100002],a3[100002],b1[100002],b2[100002],b3[100002],c[4],ans1[11];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	int t = 1;
	while(T){
		T--;
		int n;
		long long ans = 0,an;
		cin>>n;
		int cl;
		int x1 = 1;
		int x2 = 1;
		int x3 = 1;
		for(int i = 1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
			if(a1[i]>a2[i]){
				an = a1[i];
				cl = 1;
			} 
			else {
				an = a2[i];
				cl = 2; 
			}
			if(an<a3[i]){
				an = a3[i];
				cl = 3;
			}
			c[cl]++;
			if(cl == 1){
				b1[x1] = min(an-a2[i],an-a3[i]);
				x1 += 1;
			}
			if(cl == 2){
				b2[x2] = min(an-a1[i],an-a3[i]);
				x2 += 1;
			}
			if(cl == 3){
				b3[x3] = min(an-a1[i],an-a2[i]);
				x3 += 1;
			}
			ans+=an;
		}
		sort(b1+1,b1+x1);
		sort(b2+1,b2+x2);
		sort(b3+1,b3+x3);
		int k = n/2;
		for(int i = 1;i<=3;i++){
			if(c[i]>k){
				int m = c[i]-k;
				if(i == 1){
					for(int j = 1;j<=m;j++){
					ans-=b1[j];
				    }
				}else if(i==2){
					for(int j = 1;j<=m;j++){
					ans-=b2[j];
				    }
				}else{
					for(int j = 1;j<=m;j++){
					ans-=b3[j];
				    }
				}
		    }
		}
		ans1[t] = ans;
		t++;
		c[1] = c[2] = c[3] = 0;
	}
	for(int i = 1;i<t;i++){
		cout<<ans1[i]<<endl;
	}
	return 0;
}
