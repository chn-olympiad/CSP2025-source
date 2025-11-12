#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		long long n,sum=0;
		cin>>n;
		int a1=0,b1=0,c1=0,d[100010][5];
		for(int j=1;j<=n;j++){
			int a,b,c;
			cin>>a>>b>>c;
			d[j][1]=a;
			d[j][2]=b;
			d[j][3]=c;
			int f=max(a,b),g=max(a,c),h=max(b,c);
			d[j][4]=max(max(a,b),c)-min(min(f,g),h);
			if(d[j][4]<0){
				d[j][4]
		}
		for(int k=1;i<n;i++){
            for(int j=n;j>k;j--){
                if(d[j][4]<d[j+1][4]){
                    swap(d[j][1],d[j-1][1]);
                    swap(d[j][2],d[j-1][2]);
                    swap(d[j][3],d[j-1][3]);
                    swap(d[j][4],d[j-1][4]);
                }
            }
		}
		for(int j=1;j<=n;j++){
            long long e;
            if(a1>n/2){
                e=max(d[j][2],d[j][3]);
            }else if(b1>n/2){
                e=max(d[j][1],d[j][3]);
            }else if(c1>n/2){
                e=max(d[j][1],d[j][2]);
            }else{
                e=max(max(d[j][1],d[j][2]),d[j][3]);
            }
            if(e==d[j][1]){
                a1++;
            }else if(e==d[j][2]){
                b1++;
            }else if(e==d[j][3]){
                c1++;
            }
            sum+=e;
		}
		cout<<sum<<"\n";
	}
	return 0;
}
