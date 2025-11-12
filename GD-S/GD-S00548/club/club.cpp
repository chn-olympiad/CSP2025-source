#include<bits/stdc++.h>
using namespace std;
int t,n,ja,jb,jc,m;
long long num=0;
int a[100005],b[100005],c[100005];

void add(long long sum,int x){
	if(x==n){
		num=max(num,sum);
		return;
	}
	for(int i=0;i<3;i++){
		if(i==0 && ja<m){
			ja++;
			add(sum+a[x],x+1);
			ja--;
		}if(i==1 && jb<m){
			jb++;
			add(sum+b[x],x+1);
			jb--;
		}if(i==2 && jc<m){
			jc++;
			add(sum+c[x],x+1);
			jc--;
		}
	}return;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		m=n>>1,num=0;
		ja=jb=jc=0;
		for(int j=0;j<n;j++){
			cin>>a[j]>>b[j]>>c[j];
		}
		add(0,0);
		cout<<num<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
