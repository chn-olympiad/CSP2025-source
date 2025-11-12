#include<bits/stdc++.h>
using namespace std;
const int N = 200001;
string a[N],b[N],c,d;
struct f{
	int num;
	int f,b;
}ai[N],bi[N];
bool book[N] = {0};
int findb(string x){
	for(int i = 0;i<x.size();i++){
		if(x[i] == 'b'){
			return i;
		}
	}
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin >> n >> q;
    for(int i = 1;i<=n;i++){
		cin >> a[i] >> b[i];
		if(a[i] == b[i])book[i] = 1;
		ai[i].num = findb(a[i]);
		bi[i].num = findb(b[i]);
		ai[i].f = ai[i].num;
		ai[i].b = a[i].size()-ai[i].num-1;
		bi[i].f = bi[i].num;
		bi[i].b = b[i].size()-bi[i].num-1;
	}
	for(int i = 1;i<=q;i++){
		int ans = 0;
		cin >> c >> d;
		for(int j = 1;j<=n;j++){
			if(book[j] == 1)continue;
			int cb = findb(c);
			int db = findb(d);
			int cf = cb,df = db;
			int cl = c.size()-cf-1,dl = d.size()-df-1;
			if(cb - db==ai[j].num-bi[j].num&&((cl>=ai[j].b&&dl>=bi[j].b)&&(cf>=ai[j].f && df>=bi[j].f))){
				ans++;
			}
		}
		cout << ans << endl;
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
