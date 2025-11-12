#include<bits/stdc++.h>
using namespace std;
int n,a[100100][5];
int f[50][50][50][50];
struct nodeb{
    int a,b,cha;
}b[100100];
bool fa,fb;
bool cmp(nodeb a,nodeb b){
    return a.cha>b.cha;
}
int main(){
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		fa=fb=1;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][2]!=0)fa=0;
            if(a[i][3]!=0){
                fa=fb=0;
            }
        }
		if(n==2){
			int ma=0;
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					if(i==j)continue;
					ma=max(ma,a[1][i]+a[2][j]);
				}
			}
			cout<<ma<<endl;
		}else if(n==4){
			int ma=0;
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					for(int k=1;k<=3;k++){
						for(int l=1;l<=3;l++){
                            if((i==j&&j==k)||(i==j&&j==l)||(i==k&&k==l)||(j==k&&k==l))continue;
							ma=max(ma,a[1][i]+a[2][j]+a[3][k]+a[4][l]);
						}
					}
				}
			}
			cout<<ma<<endl;
		}else if(fa){
		    int aa[100100];
		    for(int i=1;i<=n;i++)aa[i]=a[i][1];
		    sort(aa+1,aa+n+1);
		    int sum=0;
		    for(int i=n;i>n/2;i--){
                sum+=aa[i];
		    }
		    cout<<sum<<endl;
		}else if(fb){
            for(int i=1;i<=n;i++){
                b[i].a=a[i][1];
                b[i].b=a[i][2];
                b[i].cha=abs(a[i][1]-a[i][2]);
            }
            sort(b+1,b+n+1,cmp);
            long long sum=0;
            int cnta=0,cntb=0;
            for(int i=1;i<=n;i++){
                if(b[i].a>b[i].b&&cnta<=n/2){
                    cnta++;
                    sum+=b[i].a;
                }else if(b[i].a==b[i].b){
                    if(cnta<cntb){
                        cnta++;
                        sum+=b[i].a;
                    }else{
                        cntb++;
                        sum+=b[i].b;
                    }
                }else if(cntb<=n/2){
                    cntb++;
                    sum+=b[i].b;
                }else{
                    cnta++;
                    sum+=b[i].a;
                }
            }
		}else if(n<=10){
		    int ans=0;
            int f[15]={0},cc[5]={0};
            for(long long i=0;i<pow(3,n);i++){
                memset(f,0,sizeof(f));
                cc[0]=cc[1]=cc[2]=0;
                long long t=i,cnnt=0;
                while(t>0){
                    f[++cnnt]=(t%3);
                    cc[t%3]++;
                    t/=3;
                }
                if(cc[0]>n/2||cc[1]>n/2||cc[2]>n/2)continue;
                int sum=0;
                for(int j=1;j<=n;j++){
                    if(f[j]==0)f[j]=3;
                    sum+=a[j][f[j]];
                }
                ans=max(ans,sum);
            }
            cout<<ans<<endl;
		}else if(n<=40){
            long long sum=0;
            for(int i=1;i<=n;i++){
                sum+=max(a[i][1],max(a[i][2],a[i][3]));
            }
            cout<<sum<<endl;
		}else{
		    long long sum=0;
            for(int i=1;i<=n;i++){
                sum+=max(a[i][1],max(a[i][2],a[i][3]));
            }
            cout<<sum<<endl;
		}
	}
	return 0;
}
