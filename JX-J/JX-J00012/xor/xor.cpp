#include<iostream>

using namespace std;

#define Debug 2
#define steam "xor"

long long n,k;
long long  a[500010];

int main(){
	if (Debug == 1){
        string c;
        cin>>c;
		freopen((string(steam)+c+".in").c_str(),"r",stdin);
	} else if (Debug == 2) {
		freopen(steam".in","r",stdin);
		freopen(steam".out","w",stdout);
	}
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    long long head=1,tail=1,cnt=0,s=a[1];
    while (true) {
        if (s<k) {
            ++tail;
            if (tail>n) {break;}
            //
            if (a[tail] == k) {
                cnt++;
                tail++;
                head=tail;
                if (tail>n) {break;}
                s = a[head];
            } else {
                s^=a[tail];
            }
            //
        } else if (s>k) {
            s^=a[head++];
            if (tail<head) {
                tail=head;
                if (tail>n) {break;}
                //
                if (a[tail] == k) {
                    cnt++;
                    tail++;
                    head=tail;
                    if (tail>n) {break;}
                    s = a[head];
                } else {
                    s^=a[tail];
                }
                //
            }
        } else if (s == k) {
            cnt++;
            tail++;
            head=tail;
            if (tail>n) {break;}
            s = a[head];
        }
    }
    cout<<cnt;
	return 0;
}// yang li 5,6 mei guo
// ~10 pts WA, fang qi le...
