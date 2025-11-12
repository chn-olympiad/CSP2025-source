#include<bits/stdc++.h>
using namespace std;

struct Man
{
    int dat[3] = {0};
    int avg = 0;
    double  del = 0;
    long long sum = 0;

    Man(int a,int b,int c)
    {
        dat[0] = a;
        dat[1] = b;
        dat[2] = c;

        sum = a + b +c;
        avg = sum / 3;
        // yudiergedecha

        // max
        int ma = 0;
        for(int i = 1;i<3;i++){
            if(dat[i]>dat[ma]) ma = i;
        }
        int mi = 0;
        for(int i = 1;i<3;i++){
            if(dat[i]<dat[mi]) mi = i;
        }

        int mid = 5 - ma - mi;
        del = dat[ma] - dat[mid];
    }

    Man()
    {

    }

};


bool cmp(Man a,Man b)
{
    if(a.del != b.del) return a.del >= b.del;
    return a.sum >= b.sum;

}

inline void choose_max(Man & man,int & club,int & d)
{
    int t = 0;
    for(int i = 0; i<3; i++)
    {
        if(man.dat[i] > man.dat[t]) t = i;
    }

    club = t;
    d = man.dat[t];

}




inline void group()
{
    int n;
    cin >> n;

    vector<Man> arr(n);
    for(int i = 0; i<n; i++)
    {
        int a, b,c;
        cin >>a >> b >> c;

        Man temp(a,b,c);
        arr[i] = temp;
    }
    sort(arr.begin(),arr.end(),cmp);
    int heap[3] = {0};
    long long sum = 0;
    int max_n = n / 2;
    for(int i = 0;i<arr.size();i++){
        int c , d;
        choose_max(arr[i],c,d);
        while(heap[c] >= max_n){
            arr[i].dat[c] = -1;
            choose_max(arr[i],c,d);
        }
        heap[c]++;
        sum += d;
    }

    cout << sum << endl;

}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    iostream::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >>t;
    for(int i = 0; i<t; i++) group();

    return 0;
}
