#inclub<iosteam>
using namespace std;
void b(int &a,int &b){
	int c = a;
	a = b;
	b = c;
}
void c(int n,int m,int a[]){
	for(int i = 1;i<=n*m;i++){
		if(a[1]<a[i+1]){
			b(a[i],a[i+1]);
		}
	}
}
int d(int r,int n,int m,int a[]){
	int v = 0;
	for(int i=1;i<=n*m;i++){
		if(a[i] == r){
			int v = i;
		}
	}
	int z = i/4;
	reture z; 
}
int f(int r,int n,int m,int a[]){
	int w = 0;
	for(int i = 1,i<=n*m,i++){
		if(a[i] == r){
			int w = i;
		}
	}
	int g = i%4;
	reture g;
}
int main(){
	int n,m;
	cin>>n>>m;
	int a,b,cc,d,e,f,g,h,i,j,k,l,o,p,q,w,aa,t,y,v;
	cin>>a>>b>>cc>>d>>e>>f>>g>>h>>i>>j>>k>>l>>o>>p>>q>>w>>aa>>t>>y>>v;
	int z[];
	z[] = {0,a,b,cc,d,e,f,g,h,i,j,k,l,o,p,q,w,aa,t,y,v}
	for(int i = 1;i<=n*m;i++){
		c(n,m,z[]);
	}
	int c = d(z[1],n,m,z);
	int r = f(z[1],n,m,z);
	cout<<c<<r;
	reture 0;
}
