//road road road road road road road road road road road
//daor daor daor daor daor daor daor daor daor daor daor
// luan xie de code 0pt 0tp 0tp w0p kwopjmpof ajewpojfwoe
// con stint A = B, B = C, C = D, D = E, E = F;

// F = G; G = Hl I EJK LKMSNQOP QRSPTJOYPJROFUVMWEWXYZ
// 18:12, 20pts
// fjiow jiod wle ala git lagit lagit lagitlagit
// cua cua  cua cua cua cau acuf uc au f acm acm
// OI OI OI OI OI OI OI OI OI OIOI OIOI OIOI OIO IOI
// OIOIOIOIOIOIOIOIOIOIOIOIOIOIOIOIOIOIOIOIOIOIO
// IOIOIOIWOUOWIOUWOIWOUOiWOUOIWOOIWOIOUWOIOIWOIOIO
// 100kb coede,
// Core Ultra 9 285K, nb
// ejiofFJ()#J(R)$J(JF$()WDJIJFWOJIGWOIWJGOIWJGIOJWOIGJWIOE
// 3.70GHz = 3 700 000 000 Hz?
// IN IN IN IN INOI OI IOI OIOIO IOIOI OIOI OIO
// AK IOI OIOIO IOI OOIO IOIO IOIOI OIO IOIO IOIO I
// IO IOAIO IAOI OAIO IAOI OAIO IOAI OIAO IOAIO AIKOIAO
// AOK OAIO IKOAI OAK IAOKI KAOIK OAIKOAIK OAI KOAIK OAI 
// AOI AOK OAI OKAOI OAI OAIK OA IKOAIOA IKAO KOAI OA
// AO IAOKO IAOIK OAI OKA OIKAO IAO IKAO IAO KAO IOA
// AIO KAO IOAK OAIK OAIK OAIK OAI KOAIO AIKO IAKO A
// A IOAKO IAO KAOI KOAIKO IKO AIK OAIK OAIK OA KOAIK 
// AK OIAOK OAIK OAI KOAIKKKKKKKKKKKKOIOIKOIOKIAOK OAI KOAI

#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1e4 + 10, M = 1e6 + 10;
int n, m, k, pre[N], kk, x, y, l;
bool ff[N];
struct node{
	int to, len, next;
} a[M << 1];
struct node2{
	int from, to, len;
	bool operator<(node2 b){
		return len < b.len;
	}
} b[M];
void add(int u, int v, int len){ 
	a[++kk] = {v, len, pre[u]};
	pre[u] = k;
}
int mit(){
	int oo = 0;
	sort(b + 1, b + 1 + m);
	for (int i = 1; i <= m; i++){
		if (ff[b[i].from] && ff[b[i].to]) continue;
		oo += b[i].len;
		ff[b[i].from] = ff[b[i].to] = true;
	}
	return oo;
}
int main(){
	//freopen("0pt.in", "w", stdin);
	//freopen("0pt.out", "r", stdout);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++){
		scanf("%d%d%d", &x, &y, &l);
		add(x, y, l); add(y, x, l);
		b[i] = {x, y, l};
	}
	if (k == 0){
		printf("%d", mit());
		return 0;
	}
	return 0;
}
