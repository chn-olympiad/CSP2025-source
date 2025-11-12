#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,a[N][4],s[4],k1[N],k2[N],k3[N],p[4],hn,w;
bool cmp1(int x,int y){
	return a[x][1]-max(a[x][2],a[x][3])>a[y][1]-max(a[y][2],a[y][3]);
}
bool cmp2(int x,int y){
	return a[x][2]-max(a[x][1],a[x][3])>a[y][2]-max(a[y][1],a[y][3]);
}
bool cmp3(int x,int y){
	return a[x][3]-max(a[x][1],a[x][2])>a[y][3]-max(a[y][1],a[y][2]);
}
void f1(){
	cin>>n;hn=n/2;
	p[1]=p[2]=p[3]=s[1]=s[2]=s[3]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>a[i][2]){
				if(a[i][1]>a[i][3]){
					s[1]+=a[i][1];p[1]++;
					k1[p[1]]=i;
				}else{
					s[3]+=a[i][3];p[3]++;
					k3[p[3]]=i;
				}
			}else{
				if(a[i][2]>a[i][3]){
					s[2]+=a[i][2];p[2]++;
					k2[p[2]]=i;
				}else{
					s[3]+=a[i][3];p[3]++;
					k3[p[3]]=i;
				}
			}
		}
}
int an1,an2;
void ch(int k){
	if(p[k]>hn){
		if(k==1)sort(k1+1,k1+1+p[1],cmp1);
		if(k==2)sort(k2+1,k2+1+p[2],cmp2);
		if(k==3)sort(k3+1,k3+1+p[3],cmp3);
		if(k==1){
			an1=2;an2=3;
		}
		if(k==2){
			an1=1;an2=3;
		}
		if(k==3){
			an1=1;an2=2;
		}
		while(p[k]>hn){
			if(k==1)w=k1[p[k]];
			if(k==2)w=k2[p[k]];
			if(k==3)w=k3[p[k]];
			if(a[w][an1]>a[w][an2]){
				p[an1]++;
				if(an1==1)k1[p[an1]]=w;
				if(an1==2)k2[p[an1]]=w;
				if(an1==3)k3[p[an1]]=w;
				s[an1]+=a[w][an1];
			}else{
				p[an2]++;
				if(an2==1)k1[p[an2]]=w;
				if(an2==2)k2[p[an2]]=w;
				if(an2==3)k3[p[an2]]=w;
				s[an2]+=a[w][an2];
			}
			s[k]-=a[w][k];
			p[k]--;
		}
		if(p[an1]>hn){
			if(an1==1)sort(k1+1,k1+1+p[1],cmp1);
			if(an1==2)sort(k2+1,k2+1+p[2],cmp2);
			if(an1==3)sort(k3+1,k3+1+p[3],cmp3);
			while(p[an1]>hn){
				if(an1==1)w=k1[p[k]];
				if(an1==2)w=k2[p[k]];
				if(an1==3)w=k3[p[k]];
				p[an2]++;
				if(an2==1)k1[p[an2]]=w;
				if(an2==2)k2[p[an2]]=w;
				if(an2==3)k3[p[an2]]=w;
				s[an2]+=a[w][an2];
				s[an1]-=a[w][an1];
				p[an1]--;
			}
		}else if(p[an2]>hn){
			if(an2==1)sort(k1+1,k1+1+p[1],cmp1);
			if(an2==2)sort(k2+1,k2+1+p[2],cmp2);
			if(an2==3)sort(k3+1,k3+1+p[3],cmp3);
			while(p[an2]>hn){
				if(an2==1)w=k1[p[k]];
				if(an2==2)w=k2[p[k]];
				if(an2==3)w=k3[p[k]];
				p[an1]++;
				if(an1==1)k1[p[an1]]=w;
				if(an1==2)k2[p[an1]]=w;
				if(an1==3)k3[p[an1]]=w;
				s[an1]+=a[w][an1];
				s[an2]-=a[w][an2];
				p[an2]--;
			}
		}
	}
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		f1();
		ch(1);ch(2);ch(3);
		cout<<s[1]+s[2]+s[3]<<'\n';
	}
	return 0;
}
