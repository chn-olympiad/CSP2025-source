#include<bits/stdc++.h>
#define forr(i,a,b) for(int i=(a);i<=(b);i++)
#define roff(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int N=2e5+10,M=5e6+10;
#define ll(i) b[i].ll
#define lr(i) b[i].lr
int n,q;
string s1,s2;
#define U unsigned long long
struct Node{
	U x,y,y1,z;
	int ll,lr;
}b[N];
U base=233;
U h1[N],h2[N],t[M]={1};
bool cmp(Node xx,Node yy){
	if(xx.y!=yy.y)return xx.y<yy.y;
	else return xx.y1<yy.y1;
}
int main(){
	ios::sync_with_stdio(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	forr(i,1,5e6){t[i]=t[i-1]*base;}
	forr(i,1,n){
		cin>>s1>>s2;
		if(s1==s2){
			b[i]={0,0,0,0};continue;
		}
		int len=s1.size(),lf,rt;
		forr(j,0,len-1){
			if(s1[j]!=s2[j]){
				lf=j;break;
			}
		}
		roff(j,len-1,0){
			if(s1[j]!=s2[j]){
				rt=j;break;
			}
		}
		roff(j,lf-1,0){
			b[i].x=b[i].x+t[lf-1-j]*(s1[j]-'a'+1);
		}
		forr(j,rt+1,len-1){
			b[i].z=b[i].z+t[j-rt-1]*(s1[j]-'a'+1);
		}
		forr(j,lf,rt){
			b[i].y+=t[j-lf]*(s1[j]-'a'+1);
			b[i].y1+=t[j-lf]*(s2[j]-'a'+1);
		}
		ll(i)=lf;
		lr(i)=len-1-rt;
	}
	if(q<=10000){
		forr(i,1,q){
			cin>>s1>>s2;
			int len=s1.size(),lf,rt,l2=s2.size();
			if(len!=l2){
				cout<<0<<endl;continue;
			}
			forr(j,0,len-1){
				if(s1[j]!=s2[j]){
					lf=j;break;
				}
			}
			U y=0,y1=0;
			roff(j,len-1,0){
				if(s1[j]!=s2[j]){
					rt=j;break;
				}
			}
			roff(j,lf-1,0){
				h1[j]=h1[j+1]+t[lf-1-j]*(s1[j]-'a'+1);
			}
			forr(j,rt+1,len-1){
				h2[j]=h2[j-1]+t[j-rt-1]*(s1[j]-'a'+1);
			}
			forr(j,lf,rt){
				y+=t[j-lf]*(s1[j]-'a'+1);
				y1+=t[j-lf]*(s2[j]-'a'+1);
			}
			int sum=0;
			forr(i,1,n){
				if(y==b[i].y&&y1==b[i].y1){
					if(lf>=ll(i)&&b[i].x==h1[lf-ll(i)]){
						if(len-1-rt>=lr(i)&&b[i].z==h2[rt+lr(i)]){
							sum++;
						}
					}
				}
			}
			cout<<sum<<endl;
			forr(i,0,len-1)h1[i]=h2[i]=0;
		}
	}else{
		sort(b+1,b+1+n,cmp);
		forr(i,1,q){
			cin>>s1>>s2;
			int len=s1.size(),lf,rt,l2=s2.size();
			if(len!=l2){
				cout<<0<<endl;continue;
			}
			forr(j,0,len-1){
				if(s1[j]!=s2[j]){
					lf=j;break;
				}
			}
			U y=0,y1=0;
			roff(j,len-1,0){
				if(s1[j]!=s2[j]){
					rt=j;break;
				}
			}
			roff(j,lf-1,0){
				h1[j]=h1[j+1]+t[lf-1-j]*(s1[j]-'a'+1);
			}
			forr(j,rt+1,len-1){
				h2[j]=h2[j-1]+t[j-rt-1]*(s1[j]-'a'+1);
			}
			forr(j,lf,rt){
				y+=t[j-lf]*(s1[j]-'a'+1);
				y1+=t[j-lf]*(s2[j]-'a'+1);
			}
			int sum=0;
			int lll=1,rr=n,lnn,rnn;
			while(lll<rr){
				int mid=((lll+rr)>>1);
				if(b[mid].y<y||(b[mid].y==y&&b[mid].y1<y1))lll=mid+1;
				else rr=mid;
			}
			lnn=lll;
			lll=1,rr=n;
			while(lll<rr){
				int mid=((lll+rr+1)>>1);
				if(b[mid].y>y||(b[mid].y==y&&b[mid].y1>y1))rr=mid-1;
				else lll=mid;
			}
			rnn=lll;
			forr(i,lnn,rnn){
				if(y==b[i].y&&y1==b[i].y1){
					if(lf>=ll(i)&&b[i].x==h1[lf-ll(i)]){
						if(len-1-rt>=lr(i)&&b[i].z==h2[rt+lr(i)]){
							sum++;
						}
					}
				}
			}
			cout<<sum<<endl;
			forr(i,0,len-1)h1[i]=h2[i]=0;
		}
		
	}
	
	return 0;
}
