#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,l,r,mid,wei[N],zc,ii,a[N],b[N],c[N],A,B,C,ans,sjz,zans,Pa,Pb,iia,iib;
int ksm(int aaa,int bbb){
    ans=1;
    while(bbb){
        if(bbb&1){
            ans=ans*aaa;
        }
        aaa=aaa*aaa;
        bbb>>=1;
    }
    return ans;
}
struct node1{
	int aa,bb;
}qa[N];
struct node2{
	int aa,bb;
}qb[N];
bool cmp1(node1 x,node1 y){
	return x.bb>y.bb;
}
bool cmp2(node2 x,node2 y){
	return x.bb>y.bb;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
		Pa=0;
		Pb=0;
        A=0;
        B=0;
        C=0;
        ans=0;
        iia=0;
        iib=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i],&b[i],&c[i]);
            if(b[i]!=0&&c[i]!=0){
				Pa=1;
			}
			if(c[i]!=0){
				Pb=1;
			}
			if(c[i]==0){
				if(b[i]!=0||a[i]!=0){
					Pb=1;
				}
			}
        }
        if(Pa==0&&Pb==1){
			for(int i=1;i<=n;i++){
				a[i]=-a[i];
			}
			sort(a+1,a+n+1);
			for(int i=1;i<=n;i++){
				a[i]=-a[i];
			}
			for(int i=1;i<=n/2;i++){
				ans=ans+a[i];
			}
		}/*
		else if(Pb==0&&Pa==1){
			for(int i=1;i<=n;i++){
				if(a[i]>=b[i]){
					ans=ans+a[i];
					iia++;
					qa[iia].aa=a[i];
					ans=ans+a[i];
					qa[iia].bb=b[i];
					A++;
					sort(qa+1,qa+A+1,cmp1);
				}
				if(b[i]>a[i]){
					ans=ans+b[i];
					iib++;
					qa[iib].aa=b[i];
					qb[iib].bb=a[i];
					B++;
				}
			}
			if(A>n/2){
				while(1){
					ans=ans-qa[A].aa;
					ans=ans+qa[A].bb;
					B++;
					qb[B].aa=qa[A].aa;
					qb[B].bb=qa[A].bb;
					A--;
					if(A<=n/2){
						break;
					}
				}
				if(B>n/2){
					ans=ans-qb[B].aa;
					B--;
					if(B<=n/2){
						break;
					}
				}
			}
			else if(B>n/2){
				while(1){
					ans=ans-qb[B].aa;
					ans=ans+qb[B].bb;
					A++;
					qa[A].aa=qb[B].aa;
					qa[A].bb=qb[B].bb;
					B--;
					if(B<=n/2){
						break;
					}
				}
				if(A>n/2){
					ans=ans-qa[A].aa;
					A--;
					if(A<=n/2){
						break;
					}
				}
			}
		}*/
        else if(n<=16&&Pa==1&&Pb==1){
            sjz=ksm(3,n);
            ans=0;
            for(int i=1;i<=sjz;i++){
                A=0;
                B=0;
                C=0;
                zc=i;
                ii=0;
                while(1){
                    if(zc<=0){
                        break;
                    }
                    ii++;
                    wei[ii]=zc%3;
                    zc=zc/3;
                }
                for(int j=1;j<=n;j++){
                    if(wei[j]==0){
                        A++;
                    }
                    if(wei[j]==1){
                        B++;
                    }
                    if(wei[j]==2){
                        C++;
                    }
                }
                zans=0;
                if(A<=n/2&&B<=n/2&&C<=n/2){
                    for(int j=1;j<=n;j++){
                        if(wei[j]==0){
                            zans=zans+a[j];
                        }
                        if(wei[j]==1){
                            zans=zans+b[j];
                        }
                        if(wei[j]==2){
                            zans=zans+c[j];
                        }
                    }
                }
                ans=max(ans,zans);
            }
        }
        cout<<ans;
        puts("");
        
    }
    return 0;
}
