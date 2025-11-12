//WTX
#include <iostream>
using namespace std;
int gtr;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int bas; cin >> bas;
    for (int i = 2;i<=n*m;i++){
	int qrq;cin >> qrq;
	if (qrq>bas) gtr++;
    }
    cout << (gtr)/n+1 << " " << (gtr/(n)%2==0?(gtr%n+1):(n-gtr%n));
}
/**
//freopen("seat.in","r",stdin);
#define int long long
I AK IOI
itn
lnog logn

RP+=2147483647

RP++
-------------------
2427FOREVER
2026FOREVER
0817FOREVER
0235FOREVER

PRAISE CCF FOREVER
AFOed

LMCC RP += INT_MAX

OI Nue Wo Qian Bai Bian
Wo Dai OI Ru Chu Lian

(NOI LINUX is not friendly for chinese characters)
**/
