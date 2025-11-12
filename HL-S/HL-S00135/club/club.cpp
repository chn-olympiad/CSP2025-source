#include <iostream>
#include <cstdio>
using namespace std;
struct person{
	int a;
	int b;
	int c;
//	int large;
//	int large_id;
	int larger;
	int larger_id;
}p[100005];
int cpy[5][2];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	for (int tt=1;tt<=t;tt++){
		for (int i=1;i<=3;i++){
			for (int j=0;j<=1;j++){
				cpy[i][j]=0;
			}
		}
		int n;
		cin >> n;
		person a_least={20004,20004,20004,20004,2},b_least={20004,20004,20004,20004,3},c_least={20004,20004,20004,20004,1};
		for (int i=1;i<=n;i++){
			scanf("%d%d%d",&p[i].a,&p[i].b,&p[i].c);
			
			if (p[i].a>p[i].b&&p[i].a>p[i].c){
				cpy[1][1]+=p[i].a;
				cpy[1][0]++;
//				p[i].large=p[i].a;
//				p[i].large_id=1;
				p[i].larger=(p[i].b>p[i].c)?p[i].b:p[i].c;
				p[i].larger_id=(p[i].b>p[i].c)?2:3;
				if (cpy[1][0]>(n/2)){
					if (a_least.larger-a_least.a<p[i].larger-p[i].a){
						cpy[1][1]-=p[i].a;
						cpy[1][0]--;
						cpy[p[i].larger_id][1]+=p[i].larger;
						cpy[p[i].larger_id][0]++;
					}else{
						cpy[1][1]-=a_least.a;
						cpy[1][0]--;
						cpy[a_least.larger_id][1]+=a_least.larger;
						cpy[a_least.larger_id][0]++;
					}
				}else{
					if (p[i].a<a_least.a){
						a_least=p[i];
					}else if (p[i].a==a_least.a){
						a_least=(p[i].larger>a_least.larger)?p[i]:a_least;
					}
				}
			}else if (p[i].b>p[i].c){
				cpy[2][1]+=p[i].b;
				cpy[2][0]++;
//				p[i].large=p[i].b;
//				p[i].large_id=2;
				p[i].larger=(p[i].a>p[i].c)?p[i].a:p[i].c;
				p[i].larger_id=(p[i].a>p[i].c)?1:3;
				
				
				if (cpy[2][0]>(n/2)){
					if (b_least.larger-b_least.b<p[i].larger-p[i].b){
						cpy[2][1]-=p[i].b;
						cpy[2][0]--;
						cpy[p[i].larger_id][1]+=p[i].larger;
						cpy[p[i].larger_id][0]++;
//						cout << "lose:" << p[i].a << " " << p[i].b<<" "<<p[i].c<<endl;
//						cout << "leave:" << b_least.a << " " << b_least.b<<" "<<b_least.c<<endl;
					}else{
						cpy[2][1]-=b_least.b;
						cpy[2][0]--;
						cpy[b_least.larger_id][1]+=b_least.larger;
						cpy[b_least.larger_id][0]++;
//						cout << "lose:" << b_least.a << " " << b_least.b<<" "<<b_least.c<<endl;
//						cout << "leave:" << p[i].a << " " << p[i].b<<" "<<p[i].c<<endl;
					}
				}else{
//					cout << "ok" << endl;
					if (p[i].b<b_least.b){
						b_least=p[i];
					}else if (p[i].b==b_least.b){
						b_least=(p[i].larger>b_least.larger)?p[i]:b_least;
					}
				}
				
				
				
			}else{
				cpy[3][1]+=p[i].c;
				cpy[3][0]++;
//				p[i].large=p[i].c;
//				p[i].large_id=3;
				p[i].larger=(p[i].a>p[i].b)?p[i].a:p[i].b;
				p[i].larger_id=(p[i].a>p[i].b)?1:2;
				
				
				
				if (cpy[3][0]>(n/2)){
					if (c_least.larger-c_least.c>p[i].larger-p[i].c){
						cpy[3][1]-=p[i].c;
						cpy[3][0]--;
						cpy[p[i].larger_id][1]+=p[i].larger;
						cpy[p[i].larger_id][0]++;
					}else{
						cpy[3][1]-=c_least.c;
						cpy[3][0]--;
						cpy[c_least.larger_id][1]+=c_least.larger;
						cpy[c_least.larger_id][0]++;
					}
				}else{
					if (p[i].c<c_least.c){
						c_least=p[i];
					}else if (p[i].c==c_least.c){
						c_least=(p[i].larger>c_least.larger)?p[i]:c_least;
					}
				}
			}
		}
//		cout << cpy[1][1] << " " << cpy[2][1] << " " << cpy[3][1] << endl;
		cout << cpy[1][1]+cpy[2][1]+cpy[3][1] << endl;
		
	}
}