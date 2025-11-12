#include<bits/stdc++.h>
using namespace std;
const int N = 100005;

struct Node{
	int a ,b ,c;
}node[N];
bool cmp1(const Node &xx,const Node &yy){//1 2 3 
	if(xx.a != yy.a) return xx.a > yy.a;
	if(xx.b != yy.b) return xx.b >yy.b;
	return xx.c > yy.c;
}
bool cmp2(const Node &xx,const Node &yy){//1 3 2 
	if(xx.a != yy.a) return xx.a > yy.a;
	if(xx.c != yy.c) return xx.c >yy.c;
	return xx.b > yy.b;
}
bool cmp3(const Node &xx,const Node &yy){// 2 1 3
	if(xx.b != yy.b) return xx.b > yy.b;
	if(xx.a != yy.a) return xx.a >yy.a;
	return xx.c > yy.c;
}
bool cmp4(const Node &xx,const Node &yy){// 2 3 1 
	if(xx.b != yy.b) return xx.b > yy.b;
	if(xx.c != yy.c) return xx.c >yy.c;
	return xx.a > yy.a;
}
bool cmp5(const Node &xx,const Node &yy){//3 1 2
	if(xx.c != yy.c) return xx.c > yy.c;
	if(xx.a != yy.a) return xx.a >yy.a;
	return xx.c > yy.c;
}
bool cmp6(const Node &xx,const Node &yy){//3 2 1 
	if(xx.c != yy.c) return xx.c > yy.c;
	if(xx.b != yy.b) return xx.b >yy.b;
	return xx.a > yy.a;
}
long long tk1(int n1){//1 2 3
	int cnt =0;
	long long sum = 0;
	int l=1;
	for(int i=1;i<=n1;i++){
		cnt++;
		if(cnt <= n1/2){
			if(l==1){
				if(node[i].a >= node[i].b){
					sum+=node[i].a;
				//	cout <<l<<" "<<i<<' ' << node[i].a << " "<<endl;
					continue;
				}
				else if(node[i].a < node[i].b){
					l=2;
					cnt = 1;
					sum += node[i].b;
					//cout <<l<<" "<<i<<' ' << node[i].b << " "<<endl;
					continue;
				}
			}
			else if(l==2){
				if(node[i].b >= node[i].c){
					sum+=node[i].b;
				//	cout<<l<<" "<<i<<' ' << node[i].b << " "<<endl;
					continue;
				}
				else if(node[i].b < node[i].c){
					l=3;
					cnt = 1;
					sum += node[i].c;
				//	cout <<l<<" "<<i<<' ' << node[i].c << " "<<endl;
					continue;
				}
			}	
			else if(l==3){
				sum += node[i].c;
				//cout <<l<<" "<<i<<' ' << node[i].c << " "<<endl;
			}
		}
		if(cnt > n1/2){
			cnt=1;
			if(l==1){ 
				l=2;
				sum+=node[i].b;
				//cout <<l<<" "<<i<<' ' << node[i].b << " "<<endl;
				continue;
			}
			if(l==2) {
				l=3;
				sum+=node[i].c;
				//cout <<l<<" "<<i<<' ' << node[i].c << " "<<endl;
				continue;
			}		
		}
	}
	//cout<<endl;
	return sum;
}
long long tk2(int n1){//1 3 2
	int cnt =0;
	long long sum = 0;
	int l=1;
	for(int i=1;i<=n1;i++){
		cnt++;
		if(cnt <= n1/2){
			if(l==1){
				if(node[i].a >= node[i].c){
					sum+=node[i].a;
				//	cout <<l<<" "<<i<<' ' << node[i].a << " "<<endl;
					continue;
				}
				else if(node[i].a < node[i].c){
					l=3;
					cnt = 1;
					sum += node[i].c;
					//cout <<l<<" "<<i<<' ' << node[i].b << " "<<endl;
					continue;
				}
			}
			else if(l==3){
				if(node[i].c >= node[i].b){
					sum+=node[i].c;
				//	cout<<l<<" "<<i<<' ' << node[i].b << " "<<endl;
					continue;
				}
				else if(node[i].c < node[i].b){
					l=2;
					cnt = 1;
					sum += node[i].b;
				//	cout <<l<<" "<<i<<' ' << node[i].c << " "<<endl;
					continue;
				}
			}	
			else if(l==2){
				sum += node[i].b;
				//cout <<l<<" "<<i<<' ' << node[i].c << " "<<endl;
			}
		}
		if(cnt > n1/2){
			cnt=1;
			if(l==1){ 
				l=3;
				sum+=node[i].c;
				//cout <<l<<" "<<i<<' ' << node[i].b << " "<<endl;
				continue;
			}
			if(l==3) {
				l=2;
				sum+=node[i].b;
				//cout <<l<<" "<<i<<' ' << node[i].c << " "<<endl;
				continue;
			}		
		}
	}
	//cout<<endl;
	return sum;
}
long long tk3(int n1){//2 1 3
	int cnt =0;
	long long sum = 0;
	int l=2;
	for(int i=1;i<=n1;i++){
		cnt++;
		if(cnt <= n1/2){
			if(l==2){
				if(node[i].b >= node[i].a){
					sum+=node[i].b;
				//	cout <<l<<" "<<i<<' ' << node[i].a << " "<<endl;
					continue;
				}
				else if(node[i].b < node[i].a){
					l=1;
					cnt = 1;
					sum += node[i].a;
					//cout <<l<<" "<<i<<' ' << node[i].b << " "<<endl;
					continue;
				}
			}
			else if(l==1){
				if(node[i].a >= node[i].c){
					sum+=node[i].a;
				//	cout<<l<<" "<<i<<' ' << node[i].b << " "<<endl;
					continue;
				}
				else if(node[i].a < node[i].c){
					l=3;
					cnt = 1;
					sum += node[i].c;
				//	cout <<l<<" "<<i<<' ' << node[i].c << " "<<endl;
					continue;
				}
			}	
			else if(l==3){
				sum += node[i].c;
				//cout <<l<<" "<<i<<' ' << node[i].c << " "<<endl;
			}
		}
		if(cnt > n1/2){
			cnt=1;
			if(l==2){ 
				l=1;
				sum+=node[i].a;
				//cout <<l<<" "<<i<<' ' << node[i].b << " "<<endl;
				continue;
			}
			if(l==1) {
				l=3;
				sum+=node[i].c;
				//cout <<l<<" "<<i<<' ' << node[i].c << " "<<endl;
				continue;
			}		
		}
	}
	//cout<<endl;
	return sum;
}
long long tk4(int n1){//2 3 1
	int cnt =0;
	long long sum = 0;
	int l=2;
	for(int i=1;i<=n1;i++){
		cnt++;
		if(cnt <= n1/2){
			if(l==2){
				if(node[i].b >= node[i].c){
					sum+=node[i].b;
				//	cout <<l<<" "<<i<<' ' << node[i].a << " "<<endl;
					continue;
				}
				else if(node[i].b < node[i].c){
					l=3;
					cnt = 1;
					sum += node[i].c;
					//cout <<l<<" "<<i<<' ' << node[i].b << " "<<endl;
					continue;
				}
			}
			else if(l==3){
				if(node[i].c >= node[i].a){
					sum+=node[i].c;
				//	cout<<l<<" "<<i<<' ' << node[i].b << " "<<endl;
					continue;
				}
				else if(node[i].c < node[i].a){
					l=1;
					cnt = 1;
					sum += node[i].a;
				//	cout <<l<<" "<<i<<' ' << node[i].c << " "<<endl;
					continue;
				}
			}	
			else if(l==1){
				sum += node[i].a;
				//cout <<l<<" "<<i<<' ' << node[i].c << " "<<endl;
			}
		}
		if(cnt > n1/2){
			cnt=1;
			if(l==2){ 
				l=3;
				sum+=node[i].c;
				//cout <<l<<" "<<i<<' ' << node[i].b << " "<<endl;
				continue;
			}
			if(l==3) {
				l=1;
				sum+=node[i].a;
				//cout <<l<<" "<<i<<' ' << node[i].c << " "<<endl;
				continue;
			}		
		}
	}
	//cout<<endl;
	return sum;
}
long long tk5(int n1){//3 1 2
	int cnt =0;
	long long sum = 0;
	int l=3;
	for(int i=1;i<=n1;i++){
		cnt++;
		if(cnt <= n1/2){
			if(l==3){
				if(node[i].c >= node[i].a){
					sum+=node[i].c;
				//	cout <<l<<" "<<i<<' ' << node[i].a << " "<<endl;
					continue;
				}
				else if(node[i].c < node[i].a){
					l=1;
					cnt = 1;
					sum += node[i].a;
					//cout <<l<<" "<<i<<' ' << node[i].b << " "<<endl;
					continue;
				}
			}
			else if(l==1){
				if(node[i].a >= node[i].b){
					sum+=node[i].a;
				//	cout<<l<<" "<<i<<' ' << node[i].b << " "<<endl;
					continue;
				}
				else if(node[i].a < node[i].b){
					l=2;
					cnt = 1;
					sum += node[i].b;
				//	cout <<l<<" "<<i<<' ' << node[i].c << " "<<endl;
					continue;
				}
			}	
			else if(l==2){
				sum += node[i].b;
				//cout <<l<<" "<<i<<' ' << node[i].c << " "<<endl;
			}
		}
		if(cnt > n1/2){
			cnt=1;
			if(l==3){ 
				l=1;
				sum+=node[i].a;
				//cout <<l<<" "<<i<<' ' << node[i].b << " "<<endl;
				continue;
			}
			if(l==1) {
				l=2;
				sum+=node[i].b;
				//cout <<l<<" "<<i<<' ' << node[i].c << " "<<endl;
				continue;
			}		
		}
	}
	//cout<<endl;
	return sum;
}
long long tk6(int n1){//3 2 1
	int cnt =0;
	long long sum = 0;
	int l=3;
	for(int i=1;i<=n1;i++){
		cnt++;
		if(cnt <= n1/2){
			if(l==3){
				if(node[i].c >= node[i].b){
					sum+=node[i].c;
				//	cout <<l<<" "<<i<<' ' << node[i].a << " "<<endl;
					continue;
				}
				else if(node[i].c < node[i].b){
					l=2;
					cnt = 1;
					sum += node[i].b;
					//cout <<l<<" "<<i<<' ' << node[i].b << " "<<endl;
					continue;
				}
			}
			else if(l==2){
				if(node[i].b >= node[i].a){
					sum+=node[i].b;
				//	cout<<l<<" "<<i<<' ' << node[i].b << " "<<endl;
					continue;
				}
				else if(node[i].b < node[i].a){
					l=1;
					cnt = 1;
					sum += node[i].a;
				//	cout <<l<<" "<<i<<' ' << node[i].c << " "<<endl;
					continue;
				}
			}	
			else if(l==1){
				sum += node[i].a;
				//cout <<l<<" "<<i<<' ' << node[i].c << " "<<endl;
			}
		}
		if(cnt > n1/2){
			cnt=1;
			if(l==3){ 
				l=2;
				sum+=node[i].b;
				//cout <<l<<" "<<i<<' ' << node[i].b << " "<<endl;
				continue;
			}
			if(l==2) {
				l=1;
				sum+=node[i].a;
				//cout <<l<<" "<<i<<' ' << node[i].c << " "<<endl;
				continue;
			}		
		}
	}
	//cout<<endl;
	return sum;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t){
		t -= 1;
		int n;
		cin >> n;
		int an[N],bn[N],cn[N];
		memset(an,0,sizeof(0));
		memset(bn,0,sizeof(0));
		memset(cn,0,sizeof(0));
		for(int i = 1 ; i <= n ;i++){
			int a1,b1,c1;
			cin >> a1 >> b1 >> c1;
			node[i].a = a1 ; node[i].b = b1 ; node[i].c = c1;
			an[i]=a1;bn[i]=b1;cn[i]=c1;
		}
		//int k1 = 0 , k2 = 0 , k2 = 0;
		sort(an+1,an+1+n);
		sort(bn+1,bn+1+n);
		sort(cn+1,cn+1+n);
		long long s1=0,s2=0,s3=0;
		int ll = n/2;
		for(int i=1;i<=ll;i++){
			s1+=an[i];
			s2+=bn[i];
			s3+=cn[i];
		}
		long long sum1;
		//cout<<s1<<endl<<s2<<endl<<s3<<endl;
		if(s1>=s2&&s1>=s3&&s2>=s3){//1 2 3 
			sort(node+1,node+1+n,cmp1);
		//	cout<<1<<endl;
			sum1 = tk1(n);
		}
		else if(s1>=s2&&s1>=s3&&s3>=s2){//1 3 2
			sort(node+1,node+1+n,cmp2);
		//	cout<<2<<endl;
			sum1 = tk2(n);
		}
		else if(s2>=s1&&s2>=s3&&s1>=s3){//2 1 3 
			sort(node+1,node+1+n,cmp3);
		//	cout<<3<<endl;
			sum1 = tk3(n);
		}
		else if(s2>=s1&&s2>=s3&&s3>=s1){//2 3 1 
			sort(node+1,node+1+n,cmp4);
		//	cout<<4<<endl;
			sum1 = tk4(n);
		}
		else if(s3>=s2&&s3>=s1&&s1>=s2){//3 1 2
			sort(node+1,node+1+n,cmp5);
		//	cout<<5<<endl;
			sum1 = tk5(n);
		}
		else if(s3>=s1&&s3>=s2&&s2>=s1){//3 2 1
			sort(node+1,node+1+n,cmp6);
		//	cout<<6<<endl;
			sum1 = tk6(n);
		}
		/*cout<<endl;
		for(int i = 1; i <= n; i++){
			cout << node[i].a <<' '<<node[i].b<<' ' <<node[i].c<<endl;
		}
		*/
		for(int i = 1 ; i <= n ; i++){ //set node -> 0
			node[i].a=0;
			node[i].b=0;
			node[i].c=0;
		}
		cout << sum1 << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
