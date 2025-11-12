#\
i\
n\
c\
l\
u\
d\
e\
<\
b\
i\
t\
s\
/\
s\
t\
d\
c\
+\
+\
.\
h\
>
#\
d\
e\
f\
i\
n\
e\
 \
a\
k\
i\
o\
i\
 \
r\
e\
t\
u\
r\
n\
 \
0
using namespace std;

struct student{
	int id,z;
}a[101];
int n,m;
bool cmp(student x,student y){
	return x.z>y.z;
}

int main(){
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
//	freopen("seat3.in","r",stdin);
//	freopen("seat3.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].z;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int x=0,y=1;
	bool fg=false;
	int ansx=-1,ansy=-1;
	for(int i=1;i<=n*m;i++){
		if(fg==false)x++;
		else x--;
		if(fg==false&&x>n){
			x--;
			y++;
			fg=true;
		}
		if(fg==true&&x<1){
			x++;
			y++;
			fg=false;
		}
//		cout<<x<<" "<<y<<"\n";
		if(a[i].id==1){
			ansx=x;
			ansy=y;
		}
	}
	cout<<ansy<<" "<<ansx;
	akioi;
}
/*
3 3
94 95 96 97 98 99 100 93 92

4 5
1 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2
*/
