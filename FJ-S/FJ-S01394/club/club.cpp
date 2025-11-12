#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100010][10],k=0,b[1000010],ans[100010]={0},c[10],l=1,d[100010],h=0,f[100010];
bool s[100010];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		c[1]=n/2;
		c[2]=n/2;
		c[3]=n/2;
		ans[l]=0;
		k=0;
		for(int j=1;j<=n;j++){
			cin>>a[j][1]>>a[j][2]>>a[j][3];
			s[j]=true;
			d[j]=3;
			if(a[j][1]==0) d[j]--;
			if(a[j][2]==0) d[j]--;
			if(a[j][3]==0) d[j]--;
			f[j]=d[j];
			b[++k]=a[j][1]*10+1;
			b[++k]=a[j][2]*10+1;
			b[++k]=a[j][3]*10+1; 
		}
		sort(b+1,b+k+1,cmp);
		for(int j=1;j<=k;j++){
			int x=b[j]%10;
			b[j]=(b[j]-x)/10;
			for(int q=1;q<=n;q++){
				if(a[q][1]==b[j]&&s[q]==true&&c[1]!=0){
					s[q]=false;
					ans[l]+=b[j];
					c[1]--;
				}
				if(a[q][2]==b[j]&&s[q]==true&&c[2]!=0){
					s[q]=false;
					ans[l]+=b[j];
					c[2]--;
				}
				if(a[q][3]==b[j]&&s[q]==true&&c[3]!=0){
					s[q]=false;
					ans[l]+=b[j];
					c[3]--;
				}
			}
		}
		h=0;
		sort(d+1,d+n+1);
		c[1]=n/2;
		c[2]=n/2;
		c[3]=n/2;
		for(int j=1;j<=n;j++){
			s[j]=true;
		}
		for(int j=1;j<=n;j++){
			for(int q=1;q<=n;q++){
				if(f[q]==d[j]){
					int e=h;
					int w=max(max(a[q][1],a[q][2]),a[q][3]);
					if(w==0) continue;
					if(a[q][1]==w&&s[q]==true&&c[1]!=0){
						s[q]=false;
						h+=w;
						c[1]--;	
					}
					if(a[q][2]==w&&s[q]==true&&c[2]!=0){
						s[q]=false;
						h+=w;
						c[2]--;
					}
					if(a[q][3]==w&&s[q]==true&&c[3]!=0){
						s[q]=false;
						h+=w;
						c[3]--;
					}
					if(h==e){
						if(a[q][1]==w){
							w=max(a[q][2],a[q][3]);
						}
						else if(a[q][2]==w){
							w=max(a[q][1],a[q][3]);
						}
						else if(a[q][3]==w){
							w=max(a[q][1],a[q][2]);
						}
						if(w==0) continue;
						if(a[q][1]==w&&s[q]==true&&c[1]!=0){
							s[q]=false;
							h+=w;
							c[1]--;	
						}
						if(a[q][2]==w&&s[q]==true&&c[2]!=0){
							s[q]=false;
							h+=w;
							c[2]--;
						}
						if(a[q][3]==w&&s[q]==true&&c[3]!=0){
							s[q]=false;
							h+=w;
							c[3]--;
						}
						if(h==e){
							w=min(min(a[q][1],a[q][2]),a[q][3]);
							if(w==0) continue;
							if(a[q][1]==w&&s[q]==true&&c[1]!=0){
								s[q]=false;
								h+=w;
								c[1]--;	
							}
							if(a[q][2]==w&&s[q]==true&&c[2]!=0){
								s[q]=false;
								h+=w;
								c[2]--;
							}
							if(a[q][3]==w&&s[q]==true&&c[3]!=0){
								s[q]=false;
								h+=w;
								c[3]--;
							}
						}
					}
				}
			}	
		}
		ans[l]=max(ans[l],h);
		l++;
	}
	for(int i=1;i<l;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
} 
