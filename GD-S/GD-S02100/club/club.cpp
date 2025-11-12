#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define cc c[j].a
#define cn1 c[j].n1
#define cn2 c[j].n2
#define cn3 c[j].n3
const int N = 2e4 + 9;
int t, n;
ll ans[10];

struct Club{
	int a[4];
	int n1, n2, n3;
	int va;//it is minus, calc by using '+'
} c[N];

void Dprint(Club v[], int size) {
	cout<<"DPRINT";
	for(int i=0;i<size;i++){
		cout<<v[i].va;
	}
	cout<<"\n";
}

void Dpush(Club v[], int &size, Club x) {//greater on the top
	//cout<<"Dpush";
	v[size++] = x;
	int tmp = x.va;
	int p = size - 1;
	int tp = p;
	if(size <= 1) return;
	do {
		/*
		cout<<tp;
		//cout<<"DPRINT~~";
		for(int i=0;i<size;i++){
			cout<<v[i].va<<" ";
		}
		cout<<"\n";
		//cout<<"Dpushing"<<tp<<"\n";//*/
		tp = ((p + 1) >> 2) - 1;
		if(v[tp].va < tmp) {
			v[p].va = v[tp].va;
			p = tp;
			//cout<<"[[SWAP"<<tp<<"\n";
		} else {
			break;
		}
	} while(tp > 0);
	v[tp] = x;
		/*cout<<"DPRINT~~";
		for(int i=0;i<size;i++){
			cout<<v[i].va<<" ";
		}
		//cout<<"\n";//*/
	//cout<<"OK\n";
}

Club Dtop(Club v[]) {
	//cout<<"Dtop";
	//cout<<"OK\n";
	return v[0];
}

void Dpop(Club v[], int &size) {
	//cout<<"Dpop";
	v[0] = v[size - 1];
	size--;
	Club tmp = v[0];
	int p = 0;
	int tp = p; 
	do {
		tp = p << 1;
		if(tp + 1 == size){
			break;
		}
		if(tp >= size){
			break;
		}
		if(tp + 2 == size){
			tp += 1;
		} else
		if(v[tp + 1].va <= v[tp + 2].va) tp += 1;
		else tp += 2;
		
		if(v[tp].va > v[p].va){
			v[p] = v[tp];
			p = tp;
		} else {
			break;
		}
	} while(tp < size);
	v[p] = tmp;
	//cout<<"OK\n";
}

int max(int a, int b, int c) {
	return max(a, max(b, c));
}

void ini() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
}

Club q[4][N];

void in_sol() {
	scanf("%d", &t);
	for(int k = 1; k <= t; k++) {
		//cout<<"START A NEW TASK\n";
		scanf("%d", &n);
		for(int j = 1; j <= n; j++) {
			scanf("%d%d%d", &cc[1], &cc[2], &cc[3]);
			//cout<<"A"<<j<<"\n";
		}
		int qsi[4] = {0, 0, 0, 0};
		int half = (int)(n / 2);
		ll now = 0;
		int cnt[4] = {0, 0, 0, 0};
		for(int j = 1; j <= n; j++) {
			//cout<<"Starting Checking "<<j<<"\n";
			//rank
			if(max(cc[1], cc[2], cc[3]) == cc[1]) {
				c[j].n1 = 1;
				if(max(cc[2], cc[3]) == cc[2]) c[j].n2 = 2, c[j].n3 = 3;
				else c[j].n2 = 3, c[j].n3 = 2;
			} else
			if(max(cc[1], cc[2], cc[3]) == cc[2]) {
				c[j].n1 = 2;
				if(max(cc[1], cc[3]) == cc[2]) c[j].n2 = 1, c[j].n3 = 3;
				else c[j].n2 = 3, c[j].n3 = 1;
			} else
			if(max(cc[1], cc[2], cc[3]) == cc[3]) {
				c[j].n1 = 3;
				if(max(cc[1], cc[2]) == cc[2]) c[j].n2 = 1, c[j].n3 = 2;
				else c[j].n2 = 2, c[j].n3 = 1;
			}
			//cout<<"Got Ranking Number of"<<j<<"\n";
			//cout<<"==n1="<<c[j].n1<<"\n";
			c[j].va = cc[cn2] - cc[cn1];
			//c[j].va2 = cc[cn3] - cc[cn2];
			if(cnt[cn1] + 1 <= half) {
				now += cc[cn1];
				cnt[cn1]++;
				Dpush(q[cn1], qsi[cn1], c[j]);
				//cout<<"Plus\n";
			} else {
				int va_a, va_b; // va_a for replacing, va_b for changing
				va_b = cc[cn2];
				va_a = cc[cn1] + Dtop(q[cn1]).va;
				//cout<<"Value of     PA:"<<va_b<<"("<<cc[cn1]<<"+("<<Dtop(q[cn1]).va<<") )    CB:"<<va_a<<"\n";
				//*
				if(va_b >= va_a) {
					//cout<<"Plus Another\n";
					now += va_b;
					cnt[cn2]++;
					Dpush(q[cn2], qsi[cn2], c[j]);
				} else {
					//cout<<"Change Before\n";
					now += va_a;
					//Dpush(q[Dtop(q[cn1]).n2], qsi[Dtop(q[cn1]).n2], Dtop(q[cn1]));
					Dpop(q[cn1], qsi[cn1]);
					Dpush(q[cn1], qsi[cn1], c[j]);
					cnt[cn1]++;
				}//*/
			}
			//cout << "qsi["<<qsi[1]<<" , "<<qsi[2]<<" , "<<qsi[3]<<"]\n";
			//cout << "ANS now is ====>"<<now<<"\n\n";
		}
		ans[k] = now;
		//printf("%lld\n", ans[k]);
		//cout<<"ONE TASK IS COMPLETE============================================\n";
	}
	for(int i = 1; i <= t; i++) {
		printf("%lld\n", ans[i]);
	}
}

int main() {
	ini();
	in_sol();
}
