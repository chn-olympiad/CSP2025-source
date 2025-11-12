#include<bits/stdc++.h>
using namespace std;

const int N=1e4+5,M=1e6+5;

string ss;
void read(){
	ss="";
	char f=getchar();
	while(f>'z'||f<'a'){
		f=getchar();
	}
	while(f>='a'&&f<='z'){
		ss=ss+f;
		f=getchar();
	}
}
void readd(){
	ss=" ";
	char f=getchar();
	while(f>'z'||f<'a'){
		f=getchar();
	}
	while(f>='a'&&f<='z'){
		ss=ss+f;
		f=getchar();
	}
}
int n,q,si[N],s1;
unsigned long long h1[N],h2[N],st[N][2],p[N],pp=1313;
string s[N][2],t[2];
bool check1(int l,int id){
	if(l+si[id]-1>s1){
		return 0;
	}
	int r=l+si[id]-1;
	return h1[r]-h1[l-1]==st[id][0]*p[l-1];
}
bool check2(int l,int id){
	if(l+si[id]-1>s1){
		return 0;
	}
	int r=l+si[id]-1;
	return h2[r]-h2[l-1]==st[id][1]*p[l-1];
}
int z[2],zz[N][2];
void yu(){
	for(int i=1;i<=n;i++){
		for(int k=0;k<si[i];k++){
			if(s[i][0][k]=='b'){
				zz[i][0]=k;
				break;
			}
		}
		for(int k=0;k<si[i];k++){
			if(s[i][1][k]=='b'){
				zz[i][1]=k;
				break;
			}
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	p[0]=1;
	for(int i=1;i<N;i++){
		p[i]=p[i-1]*pp;
	}
	scanf("%d%d",&n,&q);
	bool flag=1;
	for(int i=1;i<=n;i++){
		read();s[i][0]=ss;
		read();s[i][1]=ss;
		si[i]=s[i][0].length();
		int z1=0,z2=0;
		for(int k=0;k<si[i];k++){
			if(s[i][0][k]>'b'||s[i][1][k]>'b'){
				flag=0;
			}
			if(s[i][0][k]=='b'){
				z1++;
			}
			if(s[i][1][k]=='b'){
				z2++;
			}
			st[i][0]=st[i][0]+p[k]*s[i][0][k];
			st[i][1]=st[i][1]+p[k]*s[i][1][k];
		}
		if(flag&&z1==0||z2==0||z1>1||z2>1){
			flag=0;
		}
	}
	if(flag){
		yu();
		for(int i=1;i<=q;i++){
			readd();t[0]=ss;
		    readd();t[1]=ss;
		    s1=t[0].length();
		    if(s1!=t[1].length()){
			    printf("0\n");
			}else{
				int ans=0;
			    s1--;
				for(int k=1;k<=s1;k++){
					if(t[0][k]=='b'){
						z[0]=k-1;
						break;
					}
				}
				for(int k=1;k<=s1;k++){
					if(t[1][k]=='b'){
						z[1]=k-1;
						break;
					}
				}
				for(int i=1;i<=n;i++){
					int x=zz[i][0]-zz[i][1],xx=z[0]-z[1];
					if(x==xx){
						int l=z[0]-zz[i][0],ll=z[1]-zz[i][1];
						if(l<0||ll<0){
							continue;
						}
						int r=s1-z[0]-(si[i]-zz[i][0]),rr=s1-z[1]-(si[i]-zz[i][1]);
						if(r<0||rr<0){
							continue;
						}
						ans++;
					}
				}
				printf("%d\n",ans);	
			}
		}
		return 0;
	}
	for(int i=1;i<=q;i++){
		readd();t[0]=ss;
		readd();t[1]=ss;
		s1=t[0].length();
		if(s1!=t[1].length()){
			printf("0\n");
		}else{
			s1--;
			int ans=0;
			for(int k=1;k<=s1;k++){
				h1[k]=h1[k-1]+p[k-1]*t[0][k];
				h2[k]=h2[k-1]+p[k-1]*t[1][k];
			}
			int e=0;
			for(int k=s1;k>=1;k--){
				if(t[0][k]!=t[1][k]){
					e=k;
					break;
				}
			}
			for(int k=1;k<=s1;k++){
				if(t[0][k-1]!=t[1][k-1]){
					break;
				}
				for(int j=1;j<=n;j++){
					if(check1(k,j)&&check2(k,j)&&(si[j]+k)>=e){
						ans++;
					//	cout<<j<<' '<<k<<endl;
					}
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
} 
