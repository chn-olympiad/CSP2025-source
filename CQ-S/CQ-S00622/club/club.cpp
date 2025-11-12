#include<bits/stdc++.h>
using namespace std;

int t,n;
int a[100005],b[100005],c[100005];

struct an{
	int a,b;
	int cha;
};

struct bn{
	int a,b,c;
	int x,y;
};

struct cn{
	int cha,id,s;
};

bool cmp(an x,an y){
	return abs(x.cha)<abs(y.cha);
}

bool cmp1(cn x,cn y){
	return abs(x.cha)<abs(y.cha);
}

void pian(){
	int a,b,c,a1,b1,c1;
	cin>>a>>b>>c;
	cin>>a1>>b1>>c1;
	
	int o=max(a+b1,a+c1);
	int o1=max(b+a1,b+c1);
	int o2=max(c+a1,c+b1);
	
	cout<<max(o,max(o1,o2))<<"\n";
	
	return;
	
}

void pian1(){
	sort(a+1,a+n+1);
	
	int ans=0;
	
	for (int i=n;i>n/2;i--){
		ans+=a[i];
	}
	cout<<ans<<"\n";
	
	return ;
}

void pian2(){
	an dp[100005];
	
	int as=0,bs=0,aa=0,ba=0;
	
	for (int i=1;i<=n;i++){
		dp[i].a=a[i];
		dp[i].b=b[i];
		dp[i].cha=a[i]-b[i];
		
		if (dp[i].cha<0){
			bs++;
			ba+=dp[i].b;
		}
		else if (dp[i].cha>0){
			as++;
			aa+=dp[i].a;
		}
		else{
			aa+=dp[i].a;
			
			
		}
	}
	
	if (as!=bs){
		sort(dp+1,dp+n+1,cmp);
		
		
		if (bs>as){
			for (int i=1;i<=(bs-as)/2;i++){
				ba-=dp[i].b;
				aa+=dp[i].a;
			}
		}
		else if (bs<as){
			for (int i=1;i<=(as-bs)/2;i++){
				ba+=dp[i].b;
				aa-=dp[i].a;
			}
		}
	}
	
	cout<<aa+ba<<"\n";
	
	return ;
}

void zheng(){
	bn dp[100005];
	
	int as=0,bs=0,cs=0;
	int aa=0,ba=0,ca=0;
	
	for (int i=1;i<=n;i++){
		dp[i].a=a[i];
		dp[i].b=b[i];
		dp[i].c=c[i];
		
		dp[i].x=dp[i].a-dp[i].b;
		dp[i].y=dp[i].b-dp[i].c;
		
		if (dp[i].a>dp[i].b && dp[i].a>dp[i].c){
			as++;
			aa+=dp[i].a;
		}
		if (dp[i].b>dp[i].a && dp[i].b>dp[i].c){
			bs++;
			ba+=dp[i].b;
		}
		if (dp[i].c>dp[i].b && dp[i].c>dp[i].a){
			cs++;
			ca+=dp[i].c;
		}
	}
	
	if (as<=n/2 && bs<=n/2 && cs<=n/2){
		cout<<aa+ba+ca<<"\n";
		return ;
	}
	
	if (as>n/2){
		int o=as-n/2;
		cn ab[200005];
		int j=1;
		for (int i=1;i<=n;i++){
			ab[j].cha=dp[i].x;
			ab[j].id=i;
			ab[j].s=1;
			ab[j+1].cha=dp[i].x+dp[i].y;
			ab[j+1].id=i;
			ab[j+1].s=2;
			j+=2;
		}
		j--;
		
		sort(ab+1,ab+j+1,cmp1);
		cout<<ab[1].cha<<"\n";
	}
	
	return ; 
}

void bao(){
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	sort(c+1,c+n+1);
	
	int a1=0,b1=0,c1=0;
	int x=n,y=n,z=n;
	int ans=0;
	
	while(a1+b1+c1<n){
		if (a[x]>=b[y] && a[x]>=c[z]){
			if (a1>=n/2){
				if (b[y]>=c[z]){
					if (b1>=n/2){
						ans+=c[z];
						c1++;
						z--;
						continue;
					}
					else{
						ans+=b[y];
						b1++;
						y--;
						continue;
					}
				}
				else{
					if (c1>=n/2){
						ans+=b[y];
						b1++;
						y--;
						continue;
					}
					else{
						ans+=c[z];
						c1++;
						z--;
						continue;
					}
				}
			}
			else{
				ans+=a[x];
				a1++;
				x--;
				continue;
			}
		}
		
		else if (b[y]>=c[z] && b[y]>=a[x]){
			if (b1>=n/2){
				if (a[x]>=c[z]){
					if (a1>=n/2){
						ans+=c[z];
						c1++;
						z--;
						continue;
					}
					else{
						ans+=a[x];
						a1++;
						x--;
						continue;
					}
				}
				else{
					if (c1>=n/2){
						ans+=a[x];
						a1++;
						x--;
						continue;
					}
					else{
						ans+=c[z];
						c1++; 
						z--;
						continue;
					}
				}
			}
			if (b1<n/2){
				ans+=b[y];
				b1++;
				y--;
				continue;
			}
		}
		else if (c[z]>a[x] && c[z]>b[y]){
			if(c1>=n/2){
				if(a[x]>b[y]){
					if (a1>n/2){
						ans+=b[y];
						b1++;
						y--;
						continue;
					}
					else{
						ans+=a[x];
						a1++;
						x--;
						continue;
					}
				}
				else{
					if (b1>n/2){
						ans+=a[x];
						a1++;
						x--;
						continue;
					}
					else{
						ans+=b[y];
						b1++;
						y--;
						continue;
					}
				}
			}
			else{
				ans+=c[z];
				c1++;
				z--;
				continue;
			}
		}
	}
	
	cout<<ans<<"\n";
	
	return ;
}


int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--){
		cin>>n;
		
		
		if (n==2){
			pian(); 
			continue;
		} 
		
		bool f1=0,f2=0;
		
		for (int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if (b[i]){
				f1=1;
			}
			if (c[i]){
				f2=1;
			}
		}
		
		if (!f1 && !f2){
			pian1();
			continue;
		}
		if (!f2){
			pian2();
			continue;
		}
		
		if (n<=10){
			bao();
			continue;
		}
		
		zheng();
	}
	
	
	return 0;
}
