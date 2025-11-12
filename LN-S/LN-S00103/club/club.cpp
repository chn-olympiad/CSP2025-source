#include<bits/stdc++.h>
using namespace std;
struct satisfy {
    int i1, i2, i3;
};
struct club {
    vector<satisfy> s;
    int number;
};
struct node {
    int f1, f2, f3, id;
};
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int d1 = 0, d2 = 0, d3 = 0;
        int sum = 0;
        vector<satisfy> v(n + 1);
        vector<int> v1(n + 1), v2(n + 1), v3(n + 1);
        bool flag = 0;
        bool flag2 = 0;
        vector<bool >se;
        set<int> hasFound;
        map<vector<int>, int > mmm;
        vector<club> clubs;


        vector<int> l2(n +1);
        for(int i = 1; i <= n; i++) {
            cin >> v[i].i1 >> v[i].i2 >> v[i].i3;
            if(v[i].i1 != 0 || v[i].i3 != 0) {
                flag = 1;
            }
            if(v[i].i3 != 0) flag2 = 1;
        l2[i] = v[i].i2;
        v1[i] = v[i].i1;
        v2[i] = v[i].i2;
        v3[i] = v[i].i3;
        }
        /*
        2 3 0
        4 6 0
        1 2 0
        3 4 0
        4 5 0
        4 1 0

        3 + 6 + 4 + 5 + 3 + 1=10+8+4=22
        */
        if(flag2 == 0 ) {
            sort(v1.begin() +1, v1.begin()  + 1 + n, greater<int>());
            sort(v2.begin() +1, v2.begin()  + 1 + n, greater<int>());
            int ss1 = 0, ss2 = 0;
            for(int i =1; i <= n / 2; i ++) {
                ss1 += v1[i];
                ss2 += v2[i];
            }
            cout << ss1 + ss2 << endl;
            continue;
        }
        if(flag == 0) {
                sort(l2.begin() + 1, l2.begin()+1+n, greater<int>());
        int ssss = 0;
        for(int i = 1; i <= n / 2; i++) {
            ssss += l2[i];
        }
            cout << ssss << endl;
            continue;
        }
        for(int i = 1; i <= n; i++) {
sum+= max(max(v1[i], v2[i]), v3[i]);
        }
        for(int i = 1; i <= n; i++) {
            hasFound.insert(i%(n / 2) == 0);
        }
       // vector<node> most(n + 1);
        //for(int i = 1; i <= n; i++) {
         //   if(v[i].i1 > v[i].i2) {
          //      if(v[i].i1 > v[i].i3) {
          //          if(v[i].i3 > v[i].i2) { // 1 3 2
          //              most[i] = {v[i].i1, v[i].i3, v[i].i2, i};
           //         } else { // 1 2 3
           //             most[i] = {v[i].i1, v[i].i2, v[i].i3, i};
           //         }
         //       } else { // 3 1 2
         //           most[i] = {v[i].i3, v[i].i1, v[i].i2, i};
        //        }
        //    } else { // v[i].i1 < v[i].i2
        ////        if(v[i].i2 > v[i].i3) {
         //           if(v[i].i3 > v[i].i1) { // 2 3 1
           //             most = {v[i].i2, v[i].i3, v[i].i1, i};
          //          } else { // 2 1 3
         //               most = {v[i].i2, v[i].i1, v[i].i3, i};
          //          }
         //       } else { // 3 2 1
          //          most[i] = {v[i].i3, v[i].i2, v[i].i1, i};
          //      }
         //   }
        //}
        //sort(v1.begin() + 1, v1.begin() + 1 + n, greater<int>());
        //sort(v2.begin() + 1, v2.begin() + 1 + n, greater<int>());
        //sort(v3.begin() + 1, v3.begin() + 1 + n, greater<int>());
  //      int lim = n / 2;
//        for(int i = 1; i <= n; i++) {
          //  if(v[i].i1 > v[i].i2) {
        //        if(v[i].i3 > v[i].i1 && d3 + 1 <= lim) {//i3
      //          /    sum += v[i].i3;
    //           /     d3++;
  //            /      continue;
//             /   }
          //    /  //if(v[i].i3 < v[i].i2 && d1 +1 <= lim) {//i1
        //     / //      sum += v[i].i1;
  //          ///        d1++;
   //       ///          continue;
   //     ///        }
      // /         if(d1 +1 <= lim){ // i1
    //  /              sum += v[i].i1;
  //   /               d1++;
//                    continue;
    //            }
    //        }// v[i].i1 < v[i].i2
 //           if(v[i].i3 > v[i].i2 && d3 + 1 <= lim) { // i3
      //          sum += v[i].i3;
      //          d3++;
    //            continue;
  //          }
//            if(v[i].i3 < v[i].i1 && d2 +1 <= lim) { // i2
              //  sum += v[i].i2;
            //    d2++;
          //      continue;
        //    }
      //      if(d2 + 1 <= lim) { // i2
    //            sum += v[i].i2;
  //              d2++;
//                continue;
        //    }
        //}
        cout << sum << endl;
    }
    return 0;
}
#ifdef SHABI
hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
hhhhhhhhhhhhhhhhh
hhhhhhhhhh
hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
hhhhhhhhhhhhhhhhhhhhhhhhhshhhhhhhjjjjjjjjjjjjjjjjjjjjffffffffffffffffffffffffffffffffffffffffff
#endif // SHABI
