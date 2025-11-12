#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;

void read(int &x){
	x=0;
	char f=getchar();
	while(f>'9'||f<'0'){
		f=getchar();
	}
	while(f<='9'&&f>='0'){
		x=x*10+f-'0';
		f=getchar();
	}
}

int n,a[N][3],m,c[3],ans;
struct node{
	int id,w;
	bool operator<(const node&x) const{
		return w<x.w;
	}
};
priority_queue<node> q;

void answer(){
	read(n);
	m=n/2;
	c[0]=c[1]=c[2]=0;
	for(int i=1;i<=n;i++){
		for(int k=0;k<3;k++){
			read(a[i][k]);
		//	cout<<a[i][k]<<" ";
		}
	//	cout<<endl;
	}
	ans=0;
	for(int i=1;i<=n;i++){
		int ma=a[i][0],se=0,id=0;
		for(int k=1;k<3;k++){
			if(a[i][k]>=ma){
				se=ma;
				ma=a[i][k];
				id=k;
			}else if(a[i][k]>se){
				se=a[i][k];
			}
		}
		ans+=ma;
		if(c[id]==m){
			int w=se-ma;
			while(q.top().id!=id){
				q.pop();
			}
			if(w<q.top().w){
				ans+=q.top().w;
				q.pop();
				q.push({id,w});
			}else{
				ans+=w;
			}
		}else{
		//	cout<<i<<endl;
			c[id]++;
			q.push({id,se-ma});
		}
	}
	while(!q.empty()){
	//	cout<<q.top()<<' ';
		q.pop();
	}
//	cout<<c[0]<<" "<<c[1]<<' '<<c[2]<<endl;
	printf("%d\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	read(t);
	while(t--){
		answer();
	}
	return 0;
} 
