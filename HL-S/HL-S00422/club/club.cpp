#include<bits/stdc++.h>
/*3
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
*/

using namespace std;

struct node{
	int a,b,c,h;
}x[110000];
bool cmp(int f,int z){
	return x[f].a>x[z].a;
}
bool cmp1(int f,int z){
	return x[f].b>x[z].b;
}
bool cmp2(int f,int z){
	return x[f].c>x[z].c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	cin>>n;
	while(n--){
		int m,y1=0,y2=0,y3=0,s=0,x1[110000],x2[110000],x3[110000];
		cin>>m;
		for(int i=0;i<m;i++){
			cin>>x[i].a>>x[i].b>>x[i].c;
			if(max(max(x[i].a,x[i].b),x[i].c)==x[i].a){
				x1[y1++]=i;
			}else if(max(max(x[i].a,x[i].b),x[i].c)==x[i].b){
				x2[y2++]=i;
			}else{
				x3[y3++]=i;
			}
			
		}
		if(y1>=n/2){
			sort(x1,x1+y1,cmp);
			for(int i=n/2-1;i<y1;i++){
				if(max(x[x1[i]].b,x[x1[i]].c)==x[x1[i]].b&&y2+1<=n/2){
					x2[y2++]=i;
					continue;
				}
				x3[y3++]=i;
			}
		}
		else if(y2>=n/2){
			sort(x2,x2+y2,cmp1);
			for(int i=n/2-1;i<y2;i++){
				if(max(x[x2[i]].a,x[x2[i]].c)==x[x1[i]].a&&y1+1<=n/2){
					x1[y1++]=i;
					continue;
				}
				x3[y3++]=i;
			}
		}
		else if(y3>=n/2){
			sort(x3,x3+y3,cmp2);
			for(int i=n/2-1;i<y3;i++){
				if(max(x[x3[i]].b,x[x3[i]].a)==x[x1[i]].a&&y1+1<=n/2){
					x1[y1++]=i;
					continue;
				}
				x2[y2++]=i;
			}
		}
		for(int i=0;i<n/2;i++){
			cout<<x[x1[i]].a+x[x2[i]].b+x[x3[i]].c;
			s+=x[x1[i]].a+x[x2[i]].b+x[x3[i]].c;
		}
		cout<<s<<endl;
	}
	return 0;
} 
