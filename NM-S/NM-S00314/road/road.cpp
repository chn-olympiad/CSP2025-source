#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,h;
}a[1000010];
struct nod{
	int hj,a[10010];
}b[10];
bool cmp(node x,node y){
	return x.h<y.h;
}
bool pc(int x,int y){
	return x>y;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k,cnt=0,xi[2]={0x6f6f6f6f6f,0x6f6f6f6f6f},x;bool jc[10010]={};
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
    	cin>> a[i].a>>a[i].b>>a[i].h;
	}
	for(int i=0;i<k;i++){
		cin>>b[i].hj;
		for(int j=0;j<n;j++){
			cin>>b[i].a[j];
			if(b[i].a[j]<xi[0])xi[0]=b[i].a[j];
			else if(b[i].a[j]<xi[1])xi[1]=b[i].a[j];
		}
	}
	sort(a,a+m,cmp);
//	for(int i=0;i<k;i++)for(int j=0;j<n;j++){
//		if((jc[b[i].a[xi[0]]]==0 || jc[b[i].a[xi[1]]]==0) && (b[i].hj+b[i].a[xi[0]]+b[i].a[xi[1]])<a[j].h){
//			jc[a[j].a]==1;
//			jc[a[j].b]==1;
//			cnt+=b[i].hj+b[i].a[xi[0]]+b[i].a[xi[1]];
//			break;
//		}
//	}

	for(int i=0;i<m;i++){
		if(jc[a[i].a]==0 || jc[a[i].b]==0){
			jc[a[i].a]==1;
			jc[a[i].b]==1;
			 cnt+=a[i].h;
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout); 
    return 0;
}

