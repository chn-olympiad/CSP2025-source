#include<bits/stdc++.h>
using namespace std;
int t;
long long n,a[100010],b[100010],c[100010],x[15];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i = 1;i <= t;i++){
		long long o = 0,q = 0,p = 0;
		cin>>n;
		for(int j = 1;j <= n;j++){
			cin>>a[j]>>b[j]>>c[j];
			if(a[j]>b[j] && a[j]>c[j]) o++;
			if(b[j]>a[j] && b[j]>c[j]) p++;
			if(c[j]>b[j] && c[j]>a[j]) q++;
		}
		for(int j = 1;j <= n;j++){
		    if(o<=n/2 && q<=n/2 && p<=n/2) x[i]+=max(a[j],max(b[j],c[j]));
		    else if(o>n/2){
		    	if(p<n/2 && b[j]>c[j]){
		    		x[i]+=b[j];
					p++; 
				}else{
					x[i]+=c[j];
					q++;
				}
				o--;
			}else if(p>n/2){
				if(o<n/2 && a[j]>c[j]){
					x[i]+=a[j];
					o++;
				}else{
					x[i]+=c[j];
					q++;
				}
				p--;
			}else if(q>n/2){
				if(o<n/2 && a[j]>b[j]){
					o++;
					x[i]+=a[j];
				}else{
					p++;
					x[i]+=b[j];
				}
				q--;
			}
		}
	}
	for(int i = 1;i <= t;i++) cout<<x[i]<<endl;
	return 0;
} 
/*3
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
4 0 0*/
