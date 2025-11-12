#include <bits/stdc++.h>
const int N=1e5+7;
using namespace std;
struct Student{
	int x;
	int y;
	int z;
}stu[N];
int t,n,res,k,cha[N],pl1[N],pl2[N],pl3[N],p[N],l;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
    	cin>>n;
    	res=0,k=0,l=0;
    	int a=0,b=0,c=0,len[4];
    	len[1]=len[2]=len[3]=0;
    	for(int i=1; i<=n; ++i){
    		cin>>stu[i].x>>stu[i].y>>stu[i].z;
    		int id=1,tmp=stu[i].x;
    		if(stu[i].y>tmp){
    			id=2;
    			tmp=stu[i].y;
			}
			if(stu[i].z>tmp){
				id=3;
				tmp=stu[i].z;
			}
			int t[4];
			t[1]=tmp-stu[i].x;
			t[2]=tmp-stu[i].y;
			t[3]=tmp-stu[i].z;
			sort(t+1,t+4);
			cha[i]=t[2];
			res+=tmp;
//			cout<<"cha["<<i<<"] = "<<cha[i]<<endl;
			if(id==1) pl1[++len[1]]=i;
			else if(id==2) pl2[++len[2]]=i;
			else pl3[++len[3]]=i;
		}
		int id=1,tmp=len[1];
		b=len[2],c=len[3];
		if(b>tmp){
			id=2;
			tmp=b;
		}
		if(c>tmp){
			id=3;
			tmp=c;
		}
		if(tmp<=n/2) cout<<res<<'\n';
		else{
//			cout<<"tmp = "<<tmp<<endl;
			if(id==1){
				for(int i=1; i<=tmp; ++i){
					p[i]=cha[pl1[i]];
				}
			}
			if(id==2){
				for(int i=1; i<=tmp; ++i){
					p[i]=cha[pl2[i]];
				}
			}
			if(id==3){
				for(int i=1; i<=tmp; ++i){
					p[i]=cha[pl3[i]];
				}
			}
			sort(p+1,p+1+tmp);
			for(int i=1; i<=tmp-n/2; ++i){
				res-=p[i];
//				cout<<"res -= p["<<i<<"] = "<<p[i]<<endl;
			}
			cout<<res<<'\n';
		}
	}
	return 0;
}
/*
把3种情况转换为2种情况
把多余的拿给另一个 
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
上club5！！！ 
*/
