#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;
bool vis[N][10];
long long av[N][10];
long long n,a[N][10],b[N];
long long c1,c2,c3,c4,c5,c6;
long long maxn;

long long f(long long ans1,long long ans2,long long ans3,long long x){
	long long maxm=0;
	if(x==n){
		return 0;
	}
	if(vis[x][1]){
		if(ans1<n/2){
			maxm=max(maxm,av[x][1]);
		}
	}
	else{
		av[x][1]=f(ans1+1,ans2,ans3,x+1)+a[x][1];
		vis[x][1]=true;
		if(ans1<n/2){
			maxm=max(maxm,av[x][1]);
		}
	}
	if(vis[x][2]){
		if(ans2<n/2){
			maxm=max(maxm,av[x][2]);
		}
	}
	else{
		av[x][2]=f(ans1,ans2+1,ans3,x+1)+a[x][2];
		vis[x][2]=true;
		if(ans2<n/2){
			maxm=max(maxm,av[x][2]);
		}
	}
	if(vis[x][3]){
		if(ans3<n/2){
			maxm=max(maxm,av[x][3]);
		}
	}
	else{
		av[x][3]=f(ans1,ans2,ans3+1,x+1)+a[x][3];
		vis[x][3]=true;
		if(ans3<n/2){
			maxm=max(maxm,av[x][3]);
		}
	}
	return maxm;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    for(int P=0;P<T;P++){
		for(int i=0;i<N;i++){
			vis[i][1]=false;
			vis[i][2]=false;
			vis[i][3]=false;
		}
		bool t1=true,t2=true,t3=true;
        maxn=0;
        cin>>n;
        for(int i=0;i<n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
            }
            if(a[i][1]>a[i][2]){
                if(a[i][1]==a[i][3]){
                    c6++;
                }
                else if(a[i][1]>a[i][3]){
                    c1++;
                }
                else{
                    c3++;
                }
            }
            else if(a[i][1]<a[i][2]){
                if(a[i][3]>a[i][2]){
                    c3++;
                }
                else if(a[i][2]>a[i][3]){
                    c2++;
                }
                else{
                    c5++;
                }
            }
            else{
                if(a[i][3]>a[i][1]){
                    c3++;
                }
                else{
                    c4++;
                }
            }
        }
        if(c1<=(n/2)&&c2<=(n/2)&&c3<=(n/2)&&(c1+c2+c4)<=n&&(c1+c3+c6)<=n&&(c3+c2+c5)<=n){
            for(int i=0;i<n;i++){
                maxn+=max(max(a[i][1],a[i][2]),a[i][3]);
            }
        }
        else{
			for(int i=0;i<n;i++){
				if(a[i][1]!=0){
					t1=false;
				}
				if(a[i][2]!=0){
					t2=false;
				}
				if(a[i][3]!=0){
					t3=false;
				}
			}
			if(t1&&t2){
				for(int i=0;i<n;i++){
					b[i]=a[i][3];
				}
				sort(b,b+n);
				for(int i=n/2;i<n;i++){
					maxn+=b[i];
				}
			}
			else if(t2&&t3){
				for(int i=0;i<n;i++){
					b[i]=a[i][1];
				}
				sort(b,b+n);
				for(int i=n/2;i<n;i++){
					maxn+=b[i];
				}
			}
			else if(t1&&t3){
				for(int i=0;i<n;i++){
					b[i]=a[i][2];
				}
				sort(b,b+n);
				for(int i=n/2;i<n;i++){
					maxn+=b[i];
				}
			}
			else{
				maxn=max((f(0,0,1,1)+a[0][3]),max((f(1,0,0,1)+a[0][1]),(f(0,1,0,1)+a[0][2])));
			}
		}
        cout<<maxn<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
