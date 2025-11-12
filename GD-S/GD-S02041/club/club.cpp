#include<bits/stdc++.h>
using namespace std;

int t;
int n;
int ans;

struct g{
	int a;
	int b;
	int c;
	int fa;
	int sfa;
	short flag;
}a[100000];


int numa,numb,numc;

bool tmp(g a,g b){
	if(a.fa == b.fa){
		return a.sfa > b.sfa;
	}
	return a.fa > b.fa;
}


int maxx(int a,int b,int c){
	int big = a;
	if(b > big){
		big = b;
	}
	if(c > big){
		big = c;
	}
	return big;
}

int maxx2(int a,int b,int c){
	int big = maxx(a,b,c);
	if(a == big){
		return b > c ? b : c;
	}
	else if(b = big){
		return a > c ? a : c;
	}
	else{
		return a > b ? a : b;
	}

}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
//    cout << "first OK";
    while(t--){
    	ans = 0;
    	numa = numb = numc = 0;
//    	cout << "       --------------------    t = " << t+1 << "    --------------------       \n\n";
    	cin >> n;
    	g a[n+5];
    	for(int i = 0;i < n;i++){
    		cin >> a[i].a >> a[i].b >> a[i].c;
    		a[i].fa = maxx(a[i].a,a[i].b,a[i].c);
    		a[i].sfa = maxx2(a[i].a,a[i].b,a[i].c);
		}
		
		while(numa+numb+numc!=n){
//			cout << numa+numb+numc << "," << n << "\n";
			sort(a,a+n,tmp);
//			for(int i = 0;i < n;i++){
//				cout << "\nHere is <a[" << i << "].a> - <" << a[i].a << ">  ";
//				cout << "<a[" << i << "].b> - <" << a[i].b << ">  ";
//				cout << "<a[" << i << "].c> - <" << a[i].c << ">  ";
//				cout << "<a[" << i << "].fa> - <" << a[i].fa << ">  ";
//				cout << "<a[" << i << "].sfa> - <" << a[i].sfa << ">  \n";
//			}
//			
			
			for(int i = 0;i < n;i++){
				if(a[i].a == a[i].fa && numa < n / 2){
					numa++;
					ans+=a[i].fa;
//					cout << "     --选择 " << i << " 进入 a, 增加" << a[i].a << "个贡献点 ,目前 a 部门人数：" << numa << " / " << n/2 << "\n";
					a[i].flag=1;
					a[i].a = a[i].b = a[i].c = -1;
					
				}
				else if(a[i].b == a[i].fa && numb < n / 2){
					numb++;
					ans+=a[i].fa;
//					cout << "     --选择 " << i << " 进入 b, 增加" << a[i].b << "个贡献点 ,目前 b 部门人数：" << numb << " / " << n/2 << "\n";
					a[i].flag=2;
					a[i].a = a[i].b = a[i].c = -1;
					
					
				}
				else if(a[i].c == a[i].fa && numc < n / 2){
					numc++;
					ans+=a[i].fa;
//					cout << "     --选择 " << i << " 进入 c, 增加" << a[i].c << "个贡献点 ,目前 c 部门人数：" << numc << " / " << n/2 << "\n";
					a[i].flag=3;
					a[i].a = a[i].b = a[i].c = -1;
					
				}
				
				if(a[i].flag != 1 || a[i].flag != 2 || a[i].flag != 3){
					if(a[i].a == a[i].sfa && numa < n / 2){
						numa++;
						ans+=a[i].sfa;
//						cout << "     --2次选择 " << i << " 进入 a, 增加" << a[i].a << "个贡献点 ,目前 a 部门人数：" << numa << " / " << n/2 << "\n";
						a[i].flag=1;
						a[i].a = a[i].b = a[i].c = -1;
						
					}
					else if(a[i].b == a[i].sfa && numb < n / 2){
						numb++;
						ans+=a[i].sfa;
//						cout << "     --2次选择 " << i << " 进入 b, 增加" << a[i].b << "个贡献点 ,目前 b 部门人数：" << numb << " / " << n/2 << "\n";
						a[i].flag=2;
						a[i].a = a[i].b = a[i].c = -1;
						
					}
					else if(a[i].c == a[i].sfa && numc < n / 2){
						numc++;
						ans+=a[i].sfa;
//						cout << "     --2次选择 " << i << " 进入 c, 增加" << a[i].c << "个贡献点 ,目前 c 部门人数：" << numc << " / " << n/2 << "\n";
						a[i].flag=3;
						a[i].a = a[i].b = a[i].c = -1;
						
					}
				}
//				cout << "\n     --Here is <a[" << i << "].flag> - <" << a[i].flag << ">  \n";
//				cout << "     --Here is now ans - <" << ans << ">  \n";
//				cout << "\n\n     --Here is <anum> - <" << numa << ">  ";
//			cout << " <bnum> - <" << numb << ">  ";
//			cout << " <cnum> - <" << numc << ">  --\n";
//			cout << "\n     --Here is <ans> - <" << ans << ">  \n\n\n";
			}
		}
		cout << ans << "\n";


	}
}
